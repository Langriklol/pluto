bits    32
section         .text
        align   4
        dd      0x1BADB002
        dd      0x00
        dd      - (0x1BADB002+0x00)
        
global start
extern kernel_main                 ;External C++ function
start:
        cli                  ;Clears the interrupts
        call kernel_main     ;Continues in C++ code (kernel.cpp)
        hlt                  ;Halt the cpu
