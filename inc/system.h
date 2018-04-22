#ifndef SYSTEM_H
#define SYSTEM_H
#include "types.h"

// Get value from port; p.g. cursor handling
uint8 inportb(uint16 _port);

// Writing data to port
void outportb (uint16 _port, uint8 _data);

#endif