#ifndef PLUTO_GUI_WINDOW
#define PLUTO_GUI_WINDOW
#include "../common/types.h"
#include "../multitasking.h"
namespace pluto
{
    namespace gui
    {
        class Window
        {
            public:
                //Getters
                int getX();
                int getY();
                short getZ();
                int getSizeX();
                int getSizeY();
                //States
                bool isActive();
                //Misc
                void move(int x, int y);
                void handleExit();
                //Settters
                void setX(int x);
                void setY(int y);
                void setZ(short z);
                void setSizeX(int size);
                void setSizeY(int size);
                void active(bool active);
                //Constructors
                Window(char* name, int pid);
                Window(char* name, Task *task);
                Window(char* name, int pid, int x, int y, int z);
                Window(char* name, Task *task, int x, int y, int z);
                Window(int x, int y, int z);
                ~Window();
            private:
                int x, y; //Positioning
                short z; //Overlap
                int sizeX;
                int sizeY;
                bool active; //Do user use that window?
        };
    }
}
#endif
