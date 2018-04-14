#ifndef KSTRING_H
#define KSTRING_H

#include "types.h"
uint16 kstrlen(char* ch)
{
    uint16 i = 1;
    while(ch[i++]);
    return --i;
}

#endif