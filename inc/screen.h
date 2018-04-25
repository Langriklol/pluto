#ifndef SCREEN_H
#define SCREEN_H

#include <string.h>
#include "types.h"
#include "system.h"
#include "system.c"
#include "kstring.h"
#include "kstring.c"

int axisX = 0;
int axisY = 0;

const uint8 screenWidth = 80;
const uint8 screenHeight = 25;
const uint8 screenDepth = 2;

void clearLine(uint8 from, uint8 to);

void updateCursor();

void clearScreen();

void scrollUp(uint8 lineNumber);

void newLineCheck();

void kprintch (char c, uint8 color);

void kprint(char* ch, uint8 color);

void kprintln(char* string, uint8 color);

#endif