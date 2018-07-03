#include <gui/Window.h>
using namespace pluto::gui;

int Window::getX()
{
    return this->x;
}

int Window::getY()
{
    return this->y;
}

short Window::getZ()
{
    return this->z;
}

int Window::getSizeX()
{
    return this->sizeX;
}

int Window::getSizeY()
{
    return this->sizeY;
}

bool Window::isActive()
{
    return this->active;
}

void Window::setX(int x)
{
    this->x = x;
}

void Window::setY(int y)
{
    this->y = y;
}

void Window::setZ(short z)
{
    this->z = z;
}

void Window::setSizeX(int size)
{
    this->sizeX = size;
}

void Window::setSizeY(int size)
{
    this->sizeY = size;
}

void Window::move(int x, int y)
{
    this->setX(x);
    this->setY(y);
}

void Window::active(bool active)
{
    this->active = active;
}