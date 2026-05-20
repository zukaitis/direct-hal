#pragma once

#include "gpio/GpioPortRegisters.h"
#include "hal/gpio/GpioConfiguration.h"
#include "rcc/platform_specific/stm32u5/RccRegisters.h"

// this should be surrounded by #ifdefs, depending on the specific microcontroller variant
#include "Lqfp144.h"

#include "RegisterSet.h"

#include "stm32u5xx.h"

#include <cstdint>

namespace hal_impl {

class GpioPorts final {
 public:
  static inline constexpr RegisterSet<GpioPortRegisters> get(hal::GpioPort const port) {
    uintptr_t address {0U};
    switch(port) {
      case hal::GpioPort::kA:
        address = GPIOA_BASE_NS;
        break;
      case hal::GpioPort::kB:
        address = GPIOB_BASE_NS;
        break;
      case hal::GpioPort::kC:
        address = GPIOC_BASE_NS;
        break;
      case hal::GpioPort::kD:
        address = GPIOD_BASE_NS;
        break;
      case hal::GpioPort::kE:
        address = GPIOE_BASE_NS;
        break;
      case hal::GpioPort::kF:
        address = GPIOF_BASE_NS;
        break;
      case hal::GpioPort::kG:
        address = GPIOG_BASE_NS;
        break;
      case hal::GpioPort::kH:
        address = GPIOH_BASE_NS;
        break;
      case hal::GpioPort::kI:
        address = GPIOI_BASE_NS;
        break;
      case hal::GpioPort::kLpgpio:
        address = LPGPIO1_BASE_NS;
        break;
      default:
        // TODO: throw an error
        break;
    }
    return RegisterSet<GpioPortRegisters>(address);
  }

  static void enable_peripheral_clock(hal::GpioPort const port) {
    RccRegisters& rcc {RccRegisters::get()};
    switch(port) {
      case hal::GpioPort::kA:
        rcc.ahb2enr1_.set_bits(Mask(Bit::k0));
        break;
      case hal::GpioPort::kB:
        rcc.ahb2enr1_.set_bits(Mask(Bit::k1));
        break;
      case hal::GpioPort::kC:
        rcc.ahb2enr1_.set_bits(Mask(Bit::k2));
        break;
      case hal::GpioPort::kD:
        rcc.ahb2enr1_.set_bits(Mask(Bit::k3));
        break;
      case hal::GpioPort::kE:
        rcc.ahb2enr1_.set_bits(Mask(Bit::k4));
        break;
      case hal::GpioPort::kF:
        rcc.ahb2enr1_.set_bits(Mask(Bit::k5));
        break;
      case hal::GpioPort::kG:
        rcc.ahb2enr1_.set_bits(Mask(Bit::k6));
        break;
      case hal::GpioPort::kH:
        rcc.ahb2enr1_.set_bits(Mask(Bit::k7));
        break;
      case hal::GpioPort::kI:
        rcc.ahb2enr1_.set_bits(Mask(Bit::k8));
        break;
      case hal::GpioPort::kLpgpio:
        rcc.ahb3enr_.set_bits(Mask(Bit::k0));
        break;
      default:
        // TODO: throw an error
        break;
    }
  }
};

}
