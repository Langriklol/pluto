extern "C" void kmain()
{
        char* vidmem=(char*)0xb8000;
        vidmem[0] = 'H';
        vidmem[1] = 0x04;
        vidmem[2] = 'E';
        vidmem[3] = 0x04;
	vidmem[4] = 'L';
	vidmem[5] = 0x04;
	vidmem[6] = 'L';
	vidmem[7] = 0x04;
	vidmem[8] = 'O';
	vidmem[9] = 0x04;
	vidmem[10] = ' ';
	vidmem[11] = 0x04;
	vidmem[12] = 'G';
	vidmem[13] = 0x04;
	vidmem[14] = 'I';
	vidmem[15] = 0x04;
	vidmem[16] = 'T';
	vidmem[17] = 0x04;
	vidmem[18] = '!';
	vidmem[19] = 0x04;
	vidmem[20] = '!';
	vidmem[21] = 0x04;
	vidmem[22] = ' ';
	vidmem[23] = 0x04;
	vidmem[24] = ':';
	vidmem[25] = 0x04;
	vidmem[26] = '-';
	vidmem[27] = 0x04;
	vidmem[28] = ')';
	vidmem[29] = 0x04;
}
