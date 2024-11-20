#include "hal/gpio/GpioAlternateFunctionPin.h"

#include "GpioPorts.h"

namespace hal {

void GpioAlternateFunctionPin::configure(GpioAlternateFunction const alternate_function) const {
  hal_impl::GpioPorts::enable_peripheral_clock(port_);
  hal_impl::GpioPorts::get(port_).configure_pin_as_alternate_function(pin_, alternate_function);
}

void GpioAlternateFunctionPin::configure(Pupd const pupd_configuration) const {
  hal_impl::GpioPorts::get(port_).set_pupd(pin_, pupd_configuration);
}

}
