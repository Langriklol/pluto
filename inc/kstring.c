//
// Created by lango on 4/22/18.
//

#include "kstring.h"

uint16 kstrlen(char* ch)
{
    uint16 i = 1;
    while(ch[i++]);
    return --i;
}

uint16 kStrEql(char* origin, char* comparate)
{
    uint8 result = 1;
    uint8 size = kstrlen(origin);
}