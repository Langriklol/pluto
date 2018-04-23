char* readStr()
{
    char* buffer;
    uint8 i = 0;
    uint8 reading = 1;
    while(reading)
    {
        if(inportb(0x64) & 0x1)
        {
            switch(inportb(0x60))
            {
                /*case 1:
                          kprintch('(char)27);           Escape button
                          buffstr[i] = (char)27;
                          i++;
                          break;*/
                case 2:
                    kprintch('1', 0x0F);
                    buffer[i] = '1';
                    i++;
                    break;
                case 3:
                    kprintch('2', 0x0F);
                    buffer[i] = '2';
                    i++;
                    break;
                case 4:
                    kprintch('3', 0x0F);
                    buffer[i] = '3';
                    i++;
                    break;
                case 5:
                    kprintch('4', 0x0F);
                    buffer[i] = '4';
                    i++;
                    break;
                case 6:
                    kprintch('5', 0x0F);
                    buffer[i] = '5';
                    i++;
                    break;
                case 7:
                    kprintch('6', 0x0F);
                    buffer[i] = '6';
                    i++;
                    break;
                case 8:
                    kprintch('7', 0x0F);
                    buffer[i] = '7';
                    i++;
                    break;
                case 9:
                    kprintch('8', 0x0F);
                    buffer[i] = '8';
                    i++;
                    break;
                case 10:
                    kprintch('9', 0x0F);
                    buffer[i] = '9';
                    i++;
                    break;
                case 11:
                    kprintch('0', 0x0F);
                    buffer[i] = '0';
                    i++;
                    break;
                case 12:
                    kprintch('-', 0x0F);
                    buffer[i] = '-';
                    i++;
                    break;
                case 13:
                    kprintch('=', 0x0F);
                    buffer[i] = '=';
                    i++;
                    break;
                case 14:
                    kprintch('\b', 0x0F);
                    i--;
                    buffer[i] = 0;
                    break;
                    /* case 15:
                             kprintch('\t');          Tab button
                             buffstr[i] = '\t';
                             i++;
                             break;*/
                case 16:
                    kprintch('q', 0x0F);
                    buffer[i] = 'q';
                    i++;
                    break;
                case 17:
                    kprintch('w', 0x0F);
                    buffer[i] = 'w';
                    i++;
                    break;
                case 18:
                    kprintch('e', 0x0F);
                    buffer[i] = 'e';
                    i++;
                    break;
                case 19:
                    kprintch('r', 0x0F);
                    buffer[i] = 'r';
                    i++;
                    break;
                case 20:
                    kprintch('t', 0x0F);
                    buffer[i] = 't';
                    i++;
                    break;
                case 21:
                    kprintch('y', 0x0F);
                    buffer[i] = 'y';
                    i++;
                    break;
                case 22:
                    kprintch('u', 0x0F);
                    buffer[i] = 'u';
                    i++;
                    break;
                case 23:
                    kprintch('i', 0x0F);
                    buffer[i] = 'i';
                    i++;
                    break;
                case 24:
                    kprintch('o', 0x0F);
                    buffer[i] = 'o';
                    i++;
                    break;
                case 25:
                    kprintch('p', 0x0F);
                    buffer[i] = 'p';
                    i++;
                    break;
                case 26:
                    kprintch('[', 0x0F);
                    buffer[i] = '[';
                    i++;
                    break;
                case 27:
                    kprintch(']', 0x0F);
                    buffer[i] = ']';
                    i++;
                    break;
                case 28:
                    kprintch('\n', 0x0F);
                    buffer[i] = '\n';
                    i++;
                    reading = 0;
                    break;
                    /*  case 29:
                              kprintch('q');           Left Control
                              buffstr[i] = 'q';
                              i++;
                              break;*/
                case 30:
                    kprintch('a', 0x0F);
                    buffer[i] = 'a';
                    i++;
                    break;
                case 31:
                    kprintch('s', 0x0F);
                    buffer[i] = 's';
                    i++;
                    break;
                case 32:
                    kprintch('d', 0x0F);
                    buffer[i] = 'd';
                    i++;
                    break;
                case 33:
                    kprintch('f', 0x0F);
                    buffer[i] = 'f';
                    i++;
                    break;
                case 34:
                    kprintch('g', 0x0F);
                    buffer[i] = 'g';
                    i++;
                    break;
                case 35:
                    kprintch('h', 0x0F);
                    buffer[i] = 'h';
                    i++;
                    break;
                case 36:
                    kprintch('j', 0x0F);
                    buffer[i] = 'j';
                    i++;
                    break;
                case 37:
                    kprintch('k', 0x0F);
                    buffer[i] = 'k';
                    i++;
                    break;
                case 38:
                    kprintch('l', 0x0F);
                    buffer[i] = 'l';
                    i++;
                    break;
                case 39:
                    kprintch(';', 0x0F);
                    buffer[i] = ';';
                    i++;
                    break;
                case 40:
                    kprintch((char)44, 0x0F);               //   Single quote (')
                    buffer[i] = (char)44;
                    i++;
                    break;
                case 41:
                    kprintch((char)44, 0x0F);               // Back tick (`)
                    buffer[i] = (char)44;
                    i++;
                    break;
                    /* case 42:                                 Left shift
                               kprintch('q');
                               buffstr[i] = 'q';
                               i++;
                               break;
                       case 43:                                 \ (< for somekeyboards)
                               kprintch((char)92);
                               buffstr[i] = 'q';
                               i++;
                               break;*/
                case 44:
                    kprintch('z', 0x0F);
                    buffer[i] = 'z';
                    i++;
                    break;
                case 45:
                    kprintch('x', 0x0F);
                    buffer[i] = 'x';
                    i++;
                    break;
                case 46:
                    kprintch('c', 0x0F);
                    buffer[i] = 'c';
                    i++;
                    break;
                case 47:
                    kprintch('v', 0x0F);
                    buffer[i] = 'v';
                    i++;
                    break;
                case 48:
                    kprintch('b', 0x0F);
                    buffer[i] = 'b';
                    i++;
                    break;
                case 49:
                    kprintch('n', 0x0F);
                    buffer[i] = 'n';
                    i++;
                    break;
                case 50:
                    kprintch('m', 0x0F);
                    buffer[i] = 'm';
                    i++;
                    break;
                case 51:
                    kprintch(',', 0x0F);
                    buffer[i] = ',';
                    i++;
                    break;
                case 52:
                    kprintch('.', 0x0F);
                    buffer[i] = '.';
                    i++;
                    break;
                case 53:
                    kprintch('/', 0x0F);
                    buffer[i] = '/';
                    i++;
                    break;
                case 54:
                    kprintch('.', 0x0F);
                    buffer[i] = '.';
                    i++;
                    break;
                case 55:
                    kprintch('/', 0x0F);
                    buffer[i] = '/';
                    i++;
                    break;
                    /*case 56:
                              kprintch(' ');           Right shift
                              buffstr[i] = ' ';
                              i++;
                              break;*/
                case 57:
                    kprintch(' ', 0x0F);
                    buffer[i] = ' ';
                    i++;
                    break;
            }
        }
    }
    buffer[i] = 0;
    return buffer;
}