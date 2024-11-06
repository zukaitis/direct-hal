#pragma once

#include "GpioPort.h"

#include "stm32u5xx.h"

namespace hal_impl {

class GpioPorts {
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
      default:
        // TODO: throw an error
        break;
    }
    return *port_pointer;
  }
};

}
