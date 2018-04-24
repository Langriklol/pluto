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
    if(size != kstrlen(comparate))
    {
        result = 0;
    }
    else
    {
        for(uint8 i = 0; i <= size; i++)
        {
            if(origin[i] != comparate[i])
                result = 0;
        }
    }
    return result;
}

bool kStrStartsWith(char* string, char* needle)
{
    char* buffer;
    for(unsigned int i = 0; i < kstrlen(string); i++)
    {
        if(kStrEql(buffer, string))
        {
            return 1;
        }
        else{
            buffer[i] = string[i];
        }
    }
}

