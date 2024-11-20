#pragma once

#include "gpio/GpioPort.h"
#include "rcc/platform_specific/stm32u5/Rcc.h"

#include "stm32u5xx.h"

namespace hal_impl {

class GpioPorts final {
 public:
  static GpioPort& get(hal::GpioPort const port) {
    GpioPort* port_pointer {nullptr};
    switch(port) {
      case hal::GpioPort::kA:
        port_pointer = reinterpret_cast<GpioPort*>(GPIOA);
        break;
      case hal::GpioPort::kB:
        port_pointer = reinterpret_cast<GpioPort*>(GPIOB);
        break;
      case hal::GpioPort::kC:
        port_pointer = reinterpret_cast<GpioPort*>(GPIOC);
        break;
      case hal::GpioPort::kD:
        port_pointer = reinterpret_cast<GpioPort*>(GPIOD);
        break;
      case hal::GpioPort::kE:
        port_pointer = reinterpret_cast<GpioPort*>(GPIOE);
        break;
      case hal::GpioPort::kF:
        port_pointer = reinterpret_cast<GpioPort*>(GPIOF);
        break;
      case hal::GpioPort::kG:
        port_pointer = reinterpret_cast<GpioPort*>(GPIOG);
        break;
      case hal::GpioPort::kH:
        port_pointer = reinterpret_cast<GpioPort*>(GPIOH);
        break;
      case hal::GpioPort::kI:
        port_pointer = reinterpret_cast<GpioPort*>(GPIOI);
        break;
      case hal::GpioPort::kLpgpio:
        port_pointer = reinterpret_cast<GpioPort*>(LPGPIO1);
        break;
      default:
        // TODO: throw an error
        break;
    }
    return *port_pointer;
  }

  static void enable_peripheral_clock(hal::GpioPort const port) {
    Rcc& rcc {Rcc::get()};
    switch(port) {
      case hal::GpioPort::kA:
        rcc.ahb2enr1_.set_bit(Bit::k0);
        break;
      case hal::GpioPort::kB:
        rcc.ahb2enr1_.set_bit(Bit::k1);
        break;
      case hal::GpioPort::kC:
        rcc.ahb2enr1_.set_bit(Bit::k2);
        break;
      case hal::GpioPort::kD:
        rcc.ahb2enr1_.set_bit(Bit::k3);
        break;
      case hal::GpioPort::kE:
        rcc.ahb2enr1_.set_bit(Bit::k4);
        break;
      case hal::GpioPort::kF:
        rcc.ahb2enr1_.set_bit(Bit::k5);
        break;
      case hal::GpioPort::kG:
        rcc.ahb2enr1_.set_bit(Bit::k6);
        break;
      case hal::GpioPort::kH:
        rcc.ahb2enr1_.set_bit(Bit::k7);
        break;
      case hal::GpioPort::kI:
        rcc.ahb2enr1_.set_bit(Bit::k8);
        break;
      case hal::GpioPort::kLpgpio:
        rcc.ahb3enr_.set_bit(Bit::k0);
        break;
      default:
        // TODO: throw an error
        break;
    }
  }
};

}
