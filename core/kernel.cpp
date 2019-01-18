#include "../include/common/types.h"
#include "../include/gdt.h"
#include "../include/memorymanagement.h"
#include "../include/drivers/hardwarecommunication/interrupts.h"
#include "../include/syscalls.h"
#include "../include/drivers/hardwarecommunication/pci.h"
#include "../include/drivers/hw/driver.h"
#include "../include/drivers/hw/keyboard.h"
#include "../include/drivers/hw/mouse.h"
#include "../include/drivers/hw/vga.h"
#include "../include/drivers/hw/ata.h"
#include "../include/gui/desktop.h"
#include "../include/gui/window.h"
#include "../include/multitasking.h"

#include "../include/drivers/hw/amd_am79c973.h"
#include "../include/net/etherframe.h"
#include "../include/net/arp.h"
#include "../include/net/ipv4.h"
#include "../include/net/icmp.h"
#include "../include/net/udp.h"
#include "../include/net/tcp.h"


#define GRAPHICSMODE


using namespace pluto;
using namespace pluto::common;
using namespace pluto::drivers;
using namespace pluto::hardwarecommunication;
using namespace pluto::gui;
using namespace pluto::net;

void printf(char* str)
{
    static uint16_t* VideoMemory = (uint16_t*)0xb8000;

    static uint8_t x=0,y=0;

    for(int i = 0; str[i] != '\0'; ++i)
    {
        switch(str[i])
        {
            case '\n':
                x = 0;
                y++;
                break;
            default:
                VideoMemory[80*y+x] = (VideoMemory[80*y+x] & 0xFF00) | str[i];
                x++;
                break;
        }

        if(x >= 80)
        {
            x = 0;
            y++;
        }

        if(y >= 25)
        {
            for(y = 0; y < 25; y++)
                for(x = 0; x < 80; x++)
                    VideoMemory[80*y+x] = (VideoMemory[80*y+x] & 0xFF00) | ' ';
            x = 0;
            y = 0;
        }
    }
}

void printfHex(uint8_t key)
{
    char* foo = "00";
    char* hex = "0123456789ABCDEF";
    foo[0] = hex[(key >> 4) & 0xF];
    foo[1] = hex[key & 0xF];
    printf(foo);
}
void printfHex16(uint16_t key)
{
    printfHex((key >> 8) & 0xFF);
    printfHex( key & 0xFF);
}
void printfHex32(uint32_t key)
{
    printfHex((key >> 24) & 0xFF);
    printfHex((key >> 16) & 0xFF);
    printfHex((key >> 8) & 0xFF);
    printfHex( key & 0xFF);
}

class PrintfKeyboardEventHandler : public KeyboardEventHandler
{
public:
    void OnKeyDown(char c)
    {
        char* foo = " ";
        foo[0] = c;
        printf(foo);
    }
};

class PrintfUDPHandler : public UserDatagramProtocolHandler
{
public:
    void HandleUserDatagramProtocolMessage(UserDatagramProtocolSocket* socket, common::uint8_t* data, common::uint16_t size)
    {
        char* foo = " ";
        for(int i = 0; i < size; i++)
        {
            foo[0] = data[i];
            printf(foo);
        }
    }
};


class PrintfTCPHandler : public TransmissionControlProtocolHandler
{
public:
    bool HandleTransmissionControlProtocolMessage(TransmissionControlProtocolSocket* socket, common::uint8_t* data, common::uint16_t size)
    {
        char* foo = " ";
        for(int i = 0; i < size; i++)
        {
            foo[0] = data[i];
            printf(foo);
        }



        if(size > 9
            && data[0] == 'G'
            && data[1] == 'E'
            && data[2] == 'T'
            && data[3] == ' '
            && data[4] == '/'
            && data[5] == ' '
            && data[6] == 'H'
            && data[7] == 'T'
            && data[8] == 'T'
            && data[9] == 'P'
        )
        {
            socket->Send((uint8_t*)"HTTP/1.1 200 OK\r\nServer: PlutoOSr\nContent-Type: text/html\r\n\r\n<html><head><title>PLUTO SYSTEM</title></head><body><b>Pluto v. 0.1</b>GPPL v. 3.0 | This software uses GPPL License | This software uses GRUB (Licensed under GPPL License)</body></html>\r\n",184);
            socket->Disconnect();
        }


        return true;
    }
};


void sysprintf(char* str)
{
    asm("int $0x80" : : "a" (4), "b" (str));
}

void taskA()
{
    while(true)
        sysprintf("A");
}

void taskB()
{
    while(true)
        sysprintf("B");
}






typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors()
{
    for(constructor* i = &start_ctors; i != &end_ctors; i++)
        (*i)();
}



extern "C" void kernelMain(const void* multiboot_structure, uint32_t /*multiboot_magic*/)
{
    printf("PLUTO BOOTED SUCCESSFULLY!\n");

    GlobalDescriptorTable gdt;


    uint32_t* memupper = (uint32_t*)(((size_t)multiboot_structure) + 8);
    size_t heap = 10*1024*1024;
    MemoryManager memoryManager(heap, (*memupper)*1024 - heap - 10*1024);

    printf("heap: 0x");
    printfHex((heap >> 24) & 0xFF);
    printfHex((heap >> 16) & 0xFF);
    printfHex((heap >> 8 ) & 0xFF);
    printfHex((heap      ) & 0xFF);

    void* allocated = memoryManager.malloc(1024);
    printf("\nallocated: 0x");
    printfHex(((size_t)allocated >> 24) & 0xFF);
    printfHex(((size_t)allocated >> 16) & 0xFF);
    printfHex(((size_t)allocated >> 8 ) & 0xFF);
    printfHex(((size_t)allocated      ) & 0xFF);
    printf("\n");

    TaskManager taskManager;
    /*
    Task task1(&gdt, taskA);
    Task task2(&gdt, taskB);
    taskManager.AddTask(&task1);
    taskManager.AddTask(&task2);
    */

    InterruptManager interrupts(&gdt);
    SyscallHandler syscalls(0x80);

    printf("[INFO]: Initializing hardware (STAGE 1)... ");

    #ifdef GRAPHICSMODE
        Desktop desktop(320,200, 0x00,0x00,0xA8);
    #endif

    DriverManager drvManager;

        #ifdef GRAPHICSMODE
            KeyboardDriver keyboard(&desktop);
        #else
            PrintfKeyboardEventHandler kbhandler;
            KeyboardDriver keyboard(&kbhandler);
        #endif
        drvManager.AddDriver(&keyboard);


        #ifdef GRAPHICSMODE
            MouseDriver mouse(&desktop);
        #else
            MouseToConsole mousehandler;
            MouseDriver mouse(&mousehandler);
        #endif
        drvManager.AddDriver(&mouse);

        PeripheralComponentInterconnectController PCIController;
        PCIController.SelectDrivers(&drvManager, &interrupts);

        #ifdef GRAPHICSMODE
            VideoGraphicsArray vga;
        #endif
	printf("DONE!\n");

   	printf("[INFO]: Initializing hardware (STAGE 2)... ");
        drvManager.ActivateAll();
	printf("DONE!\n");

    printf("[INFO]: Initializing hardware (STAGE 3)... ");

    #ifdef GRAPHICSMODE
        vga.SetMode(1440,900,16);
        Window win1(&desktop, 10,10,20,20, 0xA8,0x00,0x00);
        desktop.AddChild(&win1);
        Window win2(&desktop, 40,15,30,30, 0x00,0xA8,0x00);
        desktop.AddChild(&win2);
    #endif // GRAPHICSMODE
	printf("DONE!\n\n");


    printf("\nS-ATA primary master: ");
    AdvancedTechnologyAttachment ata0m(true, 0x1F0);
    ata0m.Identify();

    printf("\nS-ATA primary slave: ");
    AdvancedTechnologyAttachment ata0s(false, 0x1F0);
    ata0s.Identify();
    ata0s.Write28(0, (uint8_t*)"PLUTO - Testing OS for learning Low-Level programming", 25);
    ata0s.Flush();
    ata0s.Read28(0, 25);

    printf("\nS-ATA secondary master: ");
    AdvancedTechnologyAttachment ata1m(true, 0x170);
    ata1m.Identify();

    printf("\nS-ATA secondary slave: ");
    AdvancedTechnologyAttachment ata1s(false, 0x170);
    ata1s.Identify();
    // third: 0x1E8
    // fourth: 0x168


    amd_am79c973* eth0 = (amd_am79c973*)(drvManager.drivers[2]);

    // IP Address
    uint8_t ip1 = 10, ip2 = 0, ip3 = 2, ip4 = 15;
    uint32_t ip_be = ((uint32_t)ip4 << 24)
                | ((uint32_t)ip3 << 16)
                | ((uint32_t)ip2 << 8)
                | (uint32_t)ip1;
    eth0->SetIPAddress(ip_be);
    EtherFrameProvider etherframe(eth0);
    AddressResolutionProtocol arp(&etherframe);
	printf("\n[INFO]: IP Address saved!");

    // IP Address of the default gateway
    uint8_t gip1 = 10, gip2 = 0, gip3 = 2, gip4 = 2;
    uint32_t gip_be = ((uint32_t)gip4 << 24)
                   | ((uint32_t)gip3 << 16)
                   | ((uint32_t)gip2 << 8)
                   | (uint32_t)gip1;

    uint8_t subnet1 = 255, subnet2 = 255, subnet3 = 255, subnet4 = 0;
    uint32_t subnet_be = ((uint32_t)subnet4 << 24)
                   | ((uint32_t)subnet3 << 16)
                   | ((uint32_t)subnet2 << 8)
                   | (uint32_t)subnet1;

    InternetProtocolProvider ipv4(&etherframe, &arp, gip_be, subnet_be);
    InternetControlMessageProtocol icmp(&ipv4);
    UserDatagramProtocolProvider udp(&ipv4);
    TransmissionControlProtocolProvider tcp(&ipv4);
	printf("\n[INFO]: IP Address of default gateway saved!");

    interrupts.Activate();

    printf("\n[INFO]: Interrupts are active!");

    //arp.BroadcastMACAddress(gip_be);

    printf("\n[INFO]: Starting TCP manager.");
    PrintfTCPHandler tcphandler;
    TransmissionControlProtocolSocket* tcpsocket = tcp.Listen(1234);
    tcp.Bind(tcpsocket, &tcphandler);
    printf("\n[INFO]: TCP manager is running!");
    tcpsocket->Send((uint8_t*)"Hello TCP!", 10);
    printf("\n[INFO]: Test TCP message sent.");

    icmp.RequestEchoReply(gip_be);

    //PrintfUDPHandler udphandler;
    //UserDatagramProtocolSocket* udpsocket = udp.Connect(gip_be, 1234);
    //udp.Bind(udpsocket, &udphandler);
    //udpsocket->Send((uint8_t*)"Hello UDP!", 10);

    //UserDatagramProtocolSocket* udpsocket = udp.Listen(1234);
    //udp.Bind(udpsocket, &udphandler);


    while(1)
    {
        #ifdef GRAPHICSMODE
            desktop.Draw(&vga);
        #endif
    }
}
