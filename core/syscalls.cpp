#include "../include/syscalls.h"

using namespace pluto;
using namespace pluto::common;
using namespace pluto::hardwarecommunication;

SyscallHandler::SyscallHandler(uint8_t InterruptNumber)
:    InterruptHandler(InterruptNumber  + InterruptManager::hardwareInterruptOffset)
{
}

SyscallHandler::~SyscallHandler()
{
}


void printf(char*);

uint32_t SyscallHandler::HandleInterrupt(uint32_t esp)
{
    CPUState* cpu = (CPUState*)esp;


    switch(cpu->eax)
    {
        case 4:
            printf((char*)cpu->ebx);
            break;

        default:
            break;
    }


    return esp;
}
