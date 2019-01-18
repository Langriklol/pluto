#include "../common/types.h"
#include "widget.h"

#ifndef PLUTO_COMPOSITEWIDGET_H
#define PLUTO_COMPOSITEWIDGET_H

namespace pluto
{
    namespace gui{

        class CompositeWidget : public Widget
        {
            private:
                Widget* children[100];
                int numChildren;
                Widget* focussedChild;

            public:
                CompositeWidget(Widget* parent,
                                common::int32_t x, common::int32_t y, common::int32_t w, common::int32_t h,
                                common::uint8_t r, common::uint8_t g, common::uint8_t b);
                ~CompositeWidget();

                virtual void GetFocus(Widget* widget);
                virtual bool AddChild(Widget* child);

                virtual void Draw(common::GraphicsContext* gc);
                virtual void OnMouseDown(common::int32_t x, common::int32_t y, common::uint8_t button);
                virtual void OnMouseUp(common::int32_t x, common::int32_t y, common::uint8_t button);
                virtual void OnMouseMove(common::int32_t oldx, common::int32_t oldy, common::int32_t newx, common::int32_t newy);

                virtual void OnKeyDown(char);
                virtual void OnKeyUp(char);
        };
    }
}
#endif //PLUTO_COMPOSITEWIDGET_H
