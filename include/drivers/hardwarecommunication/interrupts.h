#ifndef __PLUTO__HARDWARECOMMUNICATION__INTERRUPTHANDLER_H
#define __PLUTO__HARDWARECOMMUNICATION__INTERRUPTHANDLER_H

#include "../../gdt.h"
#include "../../common/types.h"
#include "port.h"
namespace pluto
{
    namespace hardwarecommunication
    {
        class InterruptHandler
        {
        protected:
            pluto::common::uint8_t InterruptNumber;
            InterruptHandler(pluto::common::uint8_t InterruptNumber);
            ~InterruptHandler();
        public:
            virtual pluto::common::uint32_t HandleInterrupt(pluto::common::uint32_t esp);
        };
    }
}

#endif
