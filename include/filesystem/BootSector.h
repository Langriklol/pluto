//
// Created by lango on 5/1/18.
//

#ifndef PLUTO_BOOTSECTOR_H
#define PLUTO_BOOTSECTOR_H

namespace pluto
{
    namespace filesystem
    {
        class BootSector
        {
        protected:
            uint8_t Ignore;  //FAT12 support
            BIOSParamaterBlock Bpb;
            BIOSParamaterBlockExt   BpbExt;
        };
    }
}

#endif //PLUTO_BOOTSECTOR_H
