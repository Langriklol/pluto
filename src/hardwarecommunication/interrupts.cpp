#include "../../include/hardwarecommunication/interrupts.h"
using namespace pluto;
using namespace pluto::common;
using namespace pluto::hardwarecommunication;

void printf(char* str);
void printfHex(uint8_t);

InterruptHandler::InterruptHandler(uint8_t InterruptNumber)
{
    this->InterruptNumber = InterruptNumber;
    interruptManager->handlers[InterruptNumber] = this;
}

InterruptHandler::~InterruptHandler()
{
    if(interruptManager->handlers[InterruptNumber] == this)
        interruptManager->handlers[InterruptNumber] = 0;
}

uint32_t InterruptHandler::HandleInterrupt(uint32_t esp)
{
    return esp;
}
