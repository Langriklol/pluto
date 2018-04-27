
#ifndef __PLUTO__DRIVERS__KEYBOARD_H
#define __PLUTO__DRIVERS__KEYBOARD_H

#include <common/types.h>
#include <hardwarecommunication/interrupts.h>
#include <drivers/driver.h>
#include <hardwarecommunication/port.h>

namespace pluto
{
    namespace drivers
    {
    
        class KeyboardEventHandler
        {
        public:
            KeyboardEventHandler();

            virtual void OnKeyDown(char);
            virtual void OnKeyUp(char);
        };
        
        class KeyboardDriver : public pluto::hardwarecommunication::InterruptHandler, public Driver
        {
            pluto::hardwarecommunication::Port8Bit dataport;
            pluto::hardwarecommunication::Port8Bit commandport;
            
            KeyboardEventHandler* handler;
        public:
            KeyboardDriver(pluto::hardwarecommunication::InterruptManager* manager, KeyboardEventHandler *handler);
            ~KeyboardDriver();
            virtual pluto::common::uint32_t HandleInterrupt(pluto::common::uint32_t esp);
            virtual void Activate();
        };

    }
}
    
#endif
