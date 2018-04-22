#ifndef SCREEN_H
#define SCREEN_H

#include <string.h>
#include "types.h"
#include "system.h"
#include "system.c"
#include "kstring.h"
#include "kstring.c"

void clearLine(uint8 from, uint8 to);

void updateCursor();

void clearScreen();

void scrollUp(uint8 lineNumber);

void newLineCheck();

void kprintch (char c, uint8 color);

void kprint(char* ch, int color);

#endif