 
#ifndef __PLUTO__GUI__WINDOW_H
#define __PLUTO__GUI__WINDOW_H

#include <gui/widget.h>
#include <gui/CompositeWidget.h>
#include <drivers/hw/mouse.h>

namespace pluto
{
    namespace gui
    {
        
        class Window : public CompositeWidget
        { 
        protected:
            bool Dragging;
            
        public:
            Window(Widget* parent,
                   common::int32_t x, common::int32_t y, common::int32_t w, common::int32_t h,
                   common::uint8_t r, common::uint8_t g, common::uint8_t b);
            ~Window();

            virtual void Move(common::int32_t y, common::int32_t x);
            virtual void Resize(common::int32_t w, common::int32_t h);
            virtual common::int32_t GetPositionY();
            virtual common::int32_t GetPositionX();
            void OnMouseDown(common::int32_t x, common::int32_t y, common::uint8_t button);
            void OnMouseUp(common::int32_t x, common::int32_t y, common::uint8_t button);
            void OnMouseMove(common::int32_t oldx, common::int32_t oldy, common::int32_t newx, common::int32_t newy);
            
        };
    }
}

#endif
