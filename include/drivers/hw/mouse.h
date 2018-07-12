
#ifndef __PLUTO__DRIVERS__MOUSE_H
#define __PLUTO__DRIVERS__MOUSE_H

#include "../../common/types.h"
#include "../../hardwarecommunication/port.h"
#include "../../drivers/driver.h"
#include "../../hardwarecommunication/interrupts.h"

namespace pluto
{
    namespace drivers
    {

        class MouseEventHandler
        {
        public:
            MouseEventHandler();

            virtual void OnActivate();
            virtual void OnMouseDown(pluto::common::uint8_t button);
            virtual void OnMouseUp(pluto::common::uint8_t button);
            virtual void OnMouseMove(int x, int y);
        };


        class MouseDriver : public pluto::hardwarecommunication::InterruptHandler, public Driver
        {
            pluto::hardwarecommunication::Port8Bit dataport;
            pluto::hardwarecommunication::Port8Bit commandport;
            pluto::common::uint8_t buffer[3];
            pluto::common::uint8_t offset;
            pluto::common::uint8_t buttons;

            MouseEventHandler* handler;
        public:
            MouseDriver(pluto::hardwarecommunication::InterruptManager* manager, MouseEventHandler* handler);
            ~MouseDriver();
            virtual pluto::common::uint32_t HandleInterrupt(pluto::common::uint32_t esp);
            virtual void Activate();
        };

    }
}

#endif
