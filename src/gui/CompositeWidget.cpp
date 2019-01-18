#include "../include/gui/CompositeWidget.h"

using namespace pluto::common;
using namespace pluto::gui;

CompositeWidget::CompositeWidget(Widget* parent,
                                 common::int32_t x, common::int32_t y, common::int32_t w, common::int32_t h,
                                 common::uint8_t r, common::uint8_t g, common::uint8_t b)
        : Widget(parent, x,y,w,h, r,g,b)
{
    focussedChild = 0;
    numChildren = 0;
}

CompositeWidget::~CompositeWidget()
{
}

void CompositeWidget::GetFocus(Widget* widget)
{
    this->focussedChild = widget;
    if(parent != 0)
        parent->GetFocus(this);
}

bool CompositeWidget::AddChild(Widget* child)
{
    if(numChildren >= 100)
        return false;
    children[numChildren++] = child;
    return true;
}


void CompositeWidget::Draw(GraphicsContext* gc)
{
    Widget::Draw(gc);
    for(int i = numChildren-1; i >= 0; --i)
        children[i]->Draw(gc);
}


void CompositeWidget::OnMouseDown(int32_t x, int32_t y, common::uint8_t button)
{
    for(int i = 0; i < numChildren; ++i)
        if(children[i]->ContainsCoordinate(x - this->x, y - this->y))
        {
            children[i]->OnMouseDown(x - this->x, y - this->y, button);
            break;
        }
}

void CompositeWidget::OnMouseUp(int32_t x, int32_t y, common::uint8_t button)
{
    for(int i = 0; i < numChildren; ++i)
        if(children[i]->ContainsCoordinate(x - this->x, y - this->y))
        {
            children[i]->OnMouseUp(x - this->x, y - this->y, button);
            break;
        }
}

void CompositeWidget::OnMouseMove(int32_t oldx, int32_t oldy, int32_t newx, int32_t newy)
{
    int firstchild = -1;
    for(int i = 0; i < numChildren; ++i)
        if(children[i]->ContainsCoordinate(oldx - this->x, oldy - this->y))
        {
            children[i]->OnMouseMove(oldx - this->x, oldy - this->y, newx - this->x, newy - this->y);
            firstchild = i;
            break;
        }

    for(int i = 0; i < numChildren; ++i)
        if(children[i]->ContainsCoordinate(newx - this->x, newy - this->y))
        {
            if(firstchild != i)
                children[i]->OnMouseMove(oldx - this->x, oldy - this->y, newx - this->x, newy - this->y);
            break;
        }
}


void CompositeWidget::OnKeyDown(char str)
{
    if(focussedChild != 0)
        focussedChild->OnKeyDown(str);
}

void CompositeWidget::OnKeyUp(char str)
{
    if(focussedChild != 0)
        focussedChild->OnKeyUp(str);
}