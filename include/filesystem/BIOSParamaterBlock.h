//
// Created by lango on 5/1/18.
//

#ifndef PLUTO_BIOSPARAMATERBLOCK_H
#define PLUTO_BIOSPARAMATERBLOCK_H

namespace pluto
{
    namespace filesystem
    {
        class BIOSParamaterBlock
        {
        protected:
            uint8_t			OEMName[8];
            uint16_t		BytesPerSector;
            uint8_t			SectorsPerCluster;
            uint16_t		ReservedSectors;
            uint8_t			NumberOfFats;
            uint16_t		NumDirEntries;
            uint16_t		NumSectors;
            uint8_t			Media;
            uint16_t		SectorsPerFat;
            uint16_t		SectorsPerTrack;
            uint16_t		HeadsPerCyl;
            uint32_t		HiddenSectors;
            uint32_t		LongSectors;
        };
    }
}

#endif //PLUTO_BIOSPARAMATERBLOCK_H
