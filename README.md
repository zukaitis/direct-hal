# direct-hal

A proof-of-concept for performance oriented C++ Hardware Abstraction Layer, which (in theory) can be purposed for many microcontroller families.

Key goals (features) of this project:
- Simple, easily mockable C++ interfaces
- Performance not worse, than that of C HAL, provided by MCU manufacturers
- Reduction of long-living volatile memory usage wherever possible, prefering to extract values directly from peripheral registers
- Easy-to-use and broadly adoptable functionality
