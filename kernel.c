#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "inc/screen.h"
#include "inc/screen.c"
#include "inc/keyboard.h"
#include "inc/keyboard.c"

void kernel_main()
{
    clearScreen();
	kprint((char*)"Hello Github! I am new mock operating system called Pluto! :-) \n", 0x04);
	bool termination = false;
	while(true)
    {
	    char* command = readStr();

        if(kStrEql(command, "terminate"))
        {
            termination = true;
            kprint("terminating", 0x0F);
        }else if(kStrEql(command, "hw"))
        {
            kprint("Hello world! I am Pluto command line!\n", 0x05);
        }else
        {
            kprint("Bad command\n", 0x04);
            kprint(command, 0x05);
        }
        if(termination)
            break;
        for(int i = 0; i < kstrlen(command); i++)
            command[i] = 0;
    }
}