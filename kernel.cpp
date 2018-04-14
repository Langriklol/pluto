#include <cstring>
#include <cstdio>
#include <string.h>

#include "inc/screen.h"

using namespace std;

extern "C" void kmain()
{
    clearScreen();
	print((char*)"Hello Github! I am new mock operating system called Pluto! :-)", 0x04);
}
