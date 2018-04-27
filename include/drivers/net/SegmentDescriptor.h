//
// Created by lango on 4/27/18.
//

#ifndef PLUTO_SEGMENTDESCRIPTOR_H
#define PLUTO_SEGMENTDESCRIPTOR_H
namespace pluto
{
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
}
#endif //PLUTO_SEGMENTDESCRIPTOR_H
