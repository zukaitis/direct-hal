#pragma once

#include "hal/gpio/GpioConfiguration.h"

namespace hal_impl {

constexpr bool is_pin_available(hal::GpioPort const port, hal::GpioPin const pin) {
    bool available {false};
    switch (port) {
        case hal::GpioPort::kA:
            available = true;
            break;
        case hal::GpioPort::kB:
            available = (hal::GpioPin::k11 != pin);
            break;
        case hal::GpioPort::kC:
        case hal::GpioPort::kD:
        case hal::GpioPort::kE:
        case hal::GpioPort::kF:
        case hal::GpioPort::kG:
            available = true;
            break;
        case hal::GpioPort::kH:
            available = (pin <= hal::GpioPin::k3);
            break;
        default:
            available = false;
    }
    return available;
}

}  // namespace hal_impl
