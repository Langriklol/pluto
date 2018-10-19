#ifndef __PLUTO__DRIVERS__MOUSE_H
#define __PLUTO__DRIVERS__MOUSE_H

#include "../../common/types.h"
#include "../../hardwarecommunication/port.h"
#include "driver.h"
#include "../hardwarecommunication/interrupts.h"

using namespace pluto::hardwarecommunication;

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

        class MouseDriver : public InterruptHandler, public Driver
        {
            pluto::hardwarecommunication::Port8Bit dataport;
            pluto::hardwarecommunication::Port8Bit commandport;
            pluto::common::uint8_t buffer[3];
            pluto::common::uint8_t offset;
            pluto::common::uint8_t buttons;

            MouseEventHandler* handler;
        public:
            MouseDriver(InterruptManager* manager, MouseEventHandler* handler);
            ~MouseDriver();
            virtual pluto::common::uint32_t HandleInterrupt(pluto::common::uint32_t esp);
            virtual void Activate();
        };

        class MouseToConsole : public MouseEventHandler
        {
           char x, y;
        public:

            MouseToConsole()
            {
                unsigned short* VideoMemory = (unsigned short*)0xb8000;
                x = 40;
                y = 12;
                VideoMemory[80*y+x] = (VideoMemory[80*y+x] & 0x0F00) << 4
                                      | (VideoMemory[80*y+x] & 0xF000) >> 4
                                      | (VideoMemory[80*y+x] & 0x00FF);
            }

            virtual void OnMouseMove(int xoffset, int yoffset)
            {
                static unsigned short* VideoMemory = (unsigned short*)0xb8000;
                VideoMemory[80*y+x] = (VideoMemory[80*y+x] & 0x0F00) << 4
                                      | (VideoMemory[80*y+x] & 0xF000) >> 4
                                      | (VideoMemory[80*y+x] & 0x00FF);

                x += xoffset;
                if(x >= 80) x = 79;
                if(x < 0) x = 0;
                y += yoffset;
                if(y >= 25) y = 24;
                if(y < 0) y = 0;

                VideoMemory[80*y+x] = (VideoMemory[80*y+x] & 0x0F00) << 4
                                      | (VideoMemory[80*y+x] & 0xF000) >> 4
                                      | (VideoMemory[80*y+x] & 0x00FF);
            }

        };
    }
}

#endif
