#include <string.h>
#include <stdio.h>
#include <stdbool.h>


#include "inc/screen.h"
#include "inc/screen.c"
#include "inc/keyboard.h"
#include "inc/keyboard.c"
#include "inc/kstring.h"
#include "inc/kstring.c"

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
        }else if(kStrEql(command, "echo"))
        {
            kprint("echo!", 0x05);
        }else
        {
            kprint("Bad command", 0x04);
        }
        if(termination)
            break;
    }
}
