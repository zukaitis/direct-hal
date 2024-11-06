#include "hal/gpio/GpioInputPin.h"

#include "GpioPorts.h"

namespace hal {

void GpioInputPin::configure() const {
  hal_impl::GpioPorts::get(port_).configure_pin_as_input(pin_);
}

bool GpioInputPin::is_high() const {
  hal_impl::GpioPorts::get(port_).is_input_pin_high(pin_);
}

}
