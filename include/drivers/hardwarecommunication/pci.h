 
#ifndef __PLUTO__HARDWARECOMMUNICATION__PCI_H
#define __PLUTO__HARDWARECOMMUNICATION__PCI_H

#include <hardwarecommunication/port.h>
#include <drivers/driver.h>
#include <common/types.h>
#include <hardwarecommunication/interrupts.h>

#include <memorymanagement.h>

namespace pluto
{
    namespace hardwarecommunication
    {

        enum BaseAddressRegisterType
        {
            MemoryMapping = 0,
            InputOutput = 1
        };
        
        
        
        class BaseAddressRegister
        {
        public:
            bool prefetchable;
            pluto::common::uint8_t* address;
            pluto::common::uint32_t size;
            BaseAddressRegisterType type;
        };
        
        
        
        class PeripheralComponentInterconnectDeviceDescriptor
        {
        public:
            pluto::common::uint32_t portBase;
            pluto::common::uint32_t interrupt;
            
            pluto::common::uint16_t bus;
            pluto::common::uint16_t device;
            pluto::common::uint16_t function;

            pluto::common::uint16_t vendor_id;
            pluto::common::uint16_t device_id;
            
            pluto::common::uint8_t class_id;
            pluto::common::uint8_t subclass_id;
            pluto::common::uint8_t interface_id;

            pluto::common::uint8_t revision;
            
            PeripheralComponentInterconnectDeviceDescriptor();
            ~PeripheralComponentInterconnectDeviceDescriptor();
            
        };


        class PeripheralComponentInterconnectController
        {
            Port32Bit dataPort;
            Port32Bit commandPort;
            
        public:
            PeripheralComponentInterconnectController();
            ~PeripheralComponentInterconnectController();
            
            pluto::common::uint32_t Read(pluto::common::uint16_t bus, pluto::common::uint16_t device, pluto::common::uint16_t function, pluto::common::uint32_t registeroffset);
            void Write(pluto::common::uint16_t bus, pluto::common::uint16_t device, pluto::common::uint16_t function, pluto::common::uint32_t registeroffset, pluto::common::uint32_t value);
            bool DeviceHasFunctions(pluto::common::uint16_t bus, pluto::common::uint16_t device);
            
            void SelectDrivers(pluto::drivers::DriverManager* driverManager, pluto::hardwarecommunication::InterruptManager* interrupts);
            pluto::drivers::Driver* GetDriver(PeripheralComponentInterconnectDeviceDescriptor dev, pluto::hardwarecommunication::InterruptManager* interrupts);
            PeripheralComponentInterconnectDeviceDescriptor GetDeviceDescriptor(pluto::common::uint16_t bus, pluto::common::uint16_t device, pluto::common::uint16_t function);
            BaseAddressRegister GetBaseAddressRegister(pluto::common::uint16_t bus, pluto::common::uint16_t device, pluto::common::uint16_t function, pluto::common::uint16_t bar);
        };

    }
}
    
#endif
