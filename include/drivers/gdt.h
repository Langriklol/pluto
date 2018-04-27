#ifndef __PLUTO__GDT_H
#define __PLUTO__GDT_H

#include <common/types.h>

namespace pluto
{
    
    class GlobalDescriptorTable
    {
        public:

            class SegmentDescriptor
            {
                private:
                    pluto::common::uint16_t limit_lo;
                    pluto::common::uint16_t base_lo;
                    pluto::common::uint8_t base_hi;
                    pluto::common::uint8_t type;
                    pluto::common::uint8_t limit_hi;
                    pluto::common::uint8_t base_vhi;

                public:
                    SegmentDescriptor(pluto::common::uint32_t base, pluto::common::uint32_t limit, pluto::common::uint8_t type);
                    pluto::common::uint32_t Base();
                    pluto::common::uint32_t Limit();
            } __attribute__((packed));

        private:
            SegmentDescriptor nullSegmentSelector;
            SegmentDescriptor unusedSegmentSelector;
            SegmentDescriptor codeSegmentSelector;
            SegmentDescriptor dataSegmentSelector;

        public:

            GlobalDescriptorTable();
            ~GlobalDescriptorTable();

            pluto::common::uint16_t CodeSegmentSelector();
            pluto::common::uint16_t DataSegmentSelector();
    };

}
    
#endif
