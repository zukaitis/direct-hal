#include "hal/gpio/GpioInputPin.h"

#include "GpioPorts.h"

namespace hal {

void GpioInputPin::configure() const {
  hal_impl::GpioPorts::enable_peripheral_clock(port_);
  hal_impl::GpioPorts::get(port_).configure_pin_as_input(pin_);
}

void GpioInputPin::configure(Pupd const pupd_configuration) const {
  configure();
  hal_impl::GpioPorts::get(port_).set_pupd(pin_, pupd_configuration);
}

bool GpioInputPin::is_high() const {
  return hal_impl::GpioPorts::get(port_).is_input_pin_high(pin_);
}

}
