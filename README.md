# direct-hal

A proof-of-concept for performance oriented C++ Hardware Abstraction Layer, which (in theory) can be purposed for many microcontroller families.

A lot of inspiration for the project comes from [this talk](https://www.youtube.com/watch?v=uwzuAGtAEFk).

Key goals (features) of this project:
- Simple, easily mockable C++ interfaces
- Performance not worse, than that of C HAL, provided by MCU manufacturers
- Reduction of long-living volatile memory usage wherever possible, preferring to extract values directly from peripheral registers
- Easy-to-use and broadly adoptable functionality
