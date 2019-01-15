#ifndef __PLUTO__SYSCALLS_H
#define __PLUTO__SYSCALLS_H

#include "common/types.h"
#include "drivers/hardwarecommunication/interrupts.h"
#include "drivers/hardwarecommunication/InterruptManager.h"
#include "multitasking.h"

namespace pluto
{

    class SyscallHandler : public hardwarecommunication::InterruptHandler
    {

    public:
        SyscallHandler(pluto::common::uint8_t InterruptNumber);
        ~SyscallHandler();

        virtual pluto::common::uint32_t HandleInterrupt(pluto::common::uint32_t esp);

    };


}


#endif
