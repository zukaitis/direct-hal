#pragma once

#if defined(STM32U5)
#include "platform_specific/stm32u5/GpioPorts.h"
#else
#error Platform unspecified or not supported
#endif
