#include <gui/widget.h>

using namespace pluto::common;
using namespace pluto::gui;


Widget::Widget(Widget* parent, int32_t x, int32_t y, int32_t w, int32_t h,
                               uint8_t r, uint8_t g, uint8_t b)
: KeyboardEventHandler()
{
    this->parent = parent;
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->r = r;
    this->g = g;
    this->b = b;
    this->Focussable = true;
}

Widget::~Widget()
{
}
            
void Widget::GetFocus(Widget* widget)
{
    if(parent != 0)
        parent->GetFocus(widget);
}

void Widget::Move(common::int32_t y, common::int32_t x)
{
    this->y = y;
    this->x = x;
}

void Widget::Resize(common::int32_t h, common::int32_t w)
{
    this->h = h;
    this->w = w;
}

int32_t Widget::GetPositionY()
{
    return this->y;
}

int32_t Widget::GetPositionX()
{
    return this->x;
}

void Widget::ModelToScreen(common::int32_t &x, common::int32_t& y)
{
    if(parent != 0)
        parent->ModelToScreen(x,y);
    x += this->x;
    y += this->y;
}
            
void Widget::Draw(GraphicsContext* gc)
{
    int X = 0;
    int Y = 0;
    ModelToScreen(X,Y);
    gc->FillRectangle(X,Y,w,h, r,g,b);
}

void Widget::OnMouseDown(common::int32_t x, common::int32_t y, common::uint8_t button)
{
    if(Focussable)
        GetFocus(this);
}

bool Widget::ContainsCoordinate(common::int32_t x, common::int32_t y)
{
    return this->x <= x && x < this->x + this->w
        && this->y <= y && y < this->y + this->h;
}

void Widget::OnMouseUp(common::int32_t x, common::int32_t y, common::uint8_t button)
{
}

void Widget::OnMouseMove(common::int32_t oldx, common::int32_t oldy, common::int32_t newx, common::int32_t newy)
{
}
