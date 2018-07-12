
#ifndef __PLUTO__HARDWARECOMMUNICATION__INTERRUPTMANAGER_H
#define __PLUTO__HARDWARECOMMUNICATION__INTERRUPTMANAGER_H

#include "../../gdt.h"
#include "../../common/types.h"
#include "../../hardwarecommunication/port.h"


namespace pluto
{
    namespace hardwarecommunication
    {
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
    }
}

#endif
