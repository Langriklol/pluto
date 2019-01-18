 
#ifndef __PLUTO__GUI__DESKTOP_H
#define __PLUTO__GUI__DESKTOP_H

#include <gui/widget.h>
#include <gui/CompositeWidget.h>
#include <drivers/hw/mouse.h>

namespace pluto
{
    namespace gui
    {
        
        class Desktop : CompositeWidget, pluto::drivers::MouseEventHandler
        {
        protected:
            common::uint32_t MouseX;
            common::uint32_t MouseY;
            
        public:
            Desktop(common::int32_t w, common::int32_t h,
                common::uint8_t r, common::uint8_t g, common::uint8_t b);
            ~Desktop();
            
            void Draw(common::GraphicsContext* gc);
            
            void OnMouseDown(pluto::common::uint8_t button);
            void OnMouseUp(pluto::common::uint8_t button);
            void OnMouseMove(int x, int y);
        };
        
    }
}


#endif
