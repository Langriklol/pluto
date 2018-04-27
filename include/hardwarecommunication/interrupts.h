
#ifndef __PLUTO__HARDWARECOMMUNICATION__INTERRUPTMANAGER_H
#define __PLUTO__HARDWARECOMMUNICATION__INTERRUPTMANAGER_H

#include <gdt.h>
#include <multitasking.h>
#include <common/types.h>
#include <hardwarecommunication/port.h>


namespace pluto
{
    namespace hardwarecommunication
    {

        class InterruptManager;

        class InterruptHandler
        {
        protected:
            pluto::common::uint8_t InterruptNumber;
            InterruptManager* interruptManager;
            InterruptHandler(InterruptManager* interruptManager, pluto::common::uint8_t InterruptNumber);
            ~InterruptHandler();
        public:
            virtual pluto::common::uint32_t HandleInterrupt(pluto::common::uint32_t esp);
        };


        class InterruptManager
        {
            friend class InterruptHandler;
            protected:

                static InterruptManager* ActiveInterruptManager;
                InterruptHandler* handlers[256];
                TaskManager *taskManager;

                struct GateDescriptor
                {
                    pluto::common::uint16_t handlerAddressLowBits;
                    pluto::common::uint16_t gdt_codeSegmentSelector;
                    pluto::common::uint8_t reserved;
                    pluto::common::uint8_t access;
                    pluto::common::uint16_t handlerAddressHighBits;
                } __attribute__((packed));

                static GateDescriptor interruptDescriptorTable[256];

                struct InterruptDescriptorTablePointer
                {
                    pluto::common::uint16_t size;
                    pluto::common::uint32_t base;
                } __attribute__((packed));

                pluto::common::uint16_t hardwareInterruptOffset;
                static void SetInterruptDescriptorTableEntry(pluto::common::uint8_t interrupt,
                    pluto::common::uint16_t codeSegmentSelectorOffset, void (*handler)(),
                    pluto::common::uint8_t DescriptorPrivilegeLevel, pluto::common::uint8_t DescriptorType);


                static void InterruptIgnore();

                static void HandleInterruptRequest0x00();
                static void HandleInterruptRequest0x01();
                static void HandleInterruptRequest0x02();
                static void HandleInterruptRequest0x03();
                static void HandleInterruptRequest0x04();
                static void HandleInterruptRequest0x05();
                static void HandleInterruptRequest0x06();
                static void HandleInterruptRequest0x07();
                static void HandleInterruptRequest0x08();
                static void HandleInterruptRequest0x09();
                static void HandleInterruptRequest0x0A();
                static void HandleInterruptRequest0x0B();
                static void HandleInterruptRequest0x0C();
                static void HandleInterruptRequest0x0D();
                static void HandleInterruptRequest0x0E();
                static void HandleInterruptRequest0x0F();
                static void HandleInterruptRequest0x31();

                static void HandleInterruptRequest0x80();

                static void HandleException0x00();
                static void HandleException0x01();
                static void HandleException0x02();
                static void HandleException0x03();
                static void HandleException0x04();
                static void HandleException0x05();
                static void HandleException0x06();
                static void HandleException0x07();
                static void HandleException0x08();
                static void HandleException0x09();
                static void HandleException0x0A();
                static void HandleException0x0B();
                static void HandleException0x0C();
                static void HandleException0x0D();
                static void HandleException0x0E();
                static void HandleException0x0F();
                static void HandleException0x10();
                static void HandleException0x11();
                static void HandleException0x12();
                static void HandleException0x13();
                
                static pluto::common::uint32_t HandleInterrupt(pluto::common::uint8_t interrupt, pluto::common::uint32_t esp);
                pluto::common::uint32_t DoHandleInterrupt(pluto::common::uint8_t interrupt, pluto::common::uint32_t esp);

                Port8BitSlow programmableInterruptControllerMasterCommandPort;
                Port8BitSlow programmableInterruptControllerMasterDataPort;
                Port8BitSlow programmableInterruptControllerSlaveCommandPort;
                Port8BitSlow programmableInterruptControllerSlaveDataPort;

            public:
                InterruptManager(pluto::common::uint16_t hardwareInterruptOffset, pluto::GlobalDescriptorTable* globalDescriptorTable, pluto::TaskManager* taskManager);
                ~InterruptManager();
                pluto::common::uint16_t HardwareInterruptOffset();
                void Activate();
                void Deactivate();
        };
        
    }
}

#endif
