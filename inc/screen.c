#include "screen.h"

void clearLine(uint8 from, uint8 to)
{
    uint16 i = screenWidth * from * screenDepth;
    char* vidmem = (char*)0xb8000;
    for(i; i < (screenWidth * (to + 1) * screenDepth); i++)
    {
        vidmem[i] = 0x0;
    }
}

void updateCursor()
{
    unsigned temp;

    temp = axisY * screenWidth * axisX;

    outportb(0x3D4, 14);                //CRT control register: Select location of cursor
    outportb(0x3D5, temp >> 8);         //Send the high byte across the bus
    outportb(0x3D4, 15);                //CRT control register: Select send low byte
    outportb(0x3D5, temp);              //Send the low byte of the cursor
}

void clearScreen()
{
    clearLine(0, screenHeight - 1);
    axisX = 0;
    axisY = 0;
    updateCursor();
}

//Similar to *nix clear command - move cursor to top and clears all
void scrollUp(uint8 lineNumber)
{
    char* vidmem = (char*)0xb8000;
    uint16 i = 0;
    for(i; i < screenWidth * (screenHeight - 1) * 2; i++){
        vidmem[i] = vidmem[i + screenWidth * 2 * lineNumber];
    }

    clearLine(screenHeight - 1 - lineNumber, screenHeight - 1);

    if((axisY - lineNumber) < 0){
        axisX, axisY = 0;
    }else{
        axisY -= lineNumber;
    }
    updateCursor();
}

void newLineCheck()
{
    if(axisY >= screenHeight - 1)
        scrollUp(1);
}

void kprintch (char c, uint8 color)
{
    char* vidmem = (char*)0xb8000;
    switch(c)
    {
        case (0x08):
            if(axisX > 0){
                axisX--;
                vidmem[(axisY * screenWidth + axisX) * screenDepth] = 0x00;
            }
            break;
        case (0x09):
            axisX = (axisX + 8 ) & ~(8 -1);
            break;
        case('\r'):
            axisX = 0;
            break;
        case('\n'):
            axisX = 0;
            axisY++;
            break;
        default:
            vidmem[((axisY * screenWidth + axisX)) * screenDepth] = c;
            vidmem[((axisY * screenWidth + axisX)) * screenDepth + 1] = color;
            axisX++;
            break;
    }
    if(axisX >= screenWidth){
        axisX = 0;
        axisY++;
    }
    newLineCheck();
    updateCursor();
}

void kprint(char* ch, uint8 color)
{
    uint16 i = 0;
    for(i; i < kstrlen(ch); i++){
        kprintch(ch[i], color);
    }
}

void kprintln(char * string, uint8 color)
{
    kprint(string, color);
    kprintch('\n', 0x00);
}