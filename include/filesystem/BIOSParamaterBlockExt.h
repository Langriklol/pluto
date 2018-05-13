//
// Created by lango on 5/1/18.
//

#ifndef PLUTO_BIOSPARAMATERBLOCKEXT_H
#define PLUTO_BIOSPARAMATERBLOCKEXT_H

namespace pluto
{
    namespace filesystem
    {
        class BIOSParamaterBlockExt
        {
        protected:
            uint32_t			SectorsPerFat32;   //sectors per FAT
            uint16_t			Flags;             //flags
            uint16_t			Version;           //version
            uint32_t			RootCluster;       //starting root directory
            uint16_t			InfoCluster;
            uint16_t			BackupBoot;        //location of bootsector copy
            uint16_t			Reserved[6];
        };
    }
}

#endif //PLUTO_BIOSPARAMATERBLOCKEXT_H
