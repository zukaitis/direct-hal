#include "hal/gpio/GpioInputPin.h"

#include "GpioPorts.h"

namespace hal {

void GpioInputPin::configure() const {
  hal_impl::GpioPorts::enable_peripheral_clock(port_);
  port_registers_->configure_pin_as_input(pin_);
}

void GpioInputPin::configure(Pupd const pupd_configuration) const {
  configure();
  port_registers_->set_pupd(pin_, pupd_configuration);
}

bool GpioInputPin::is_high() const {
  return port_registers_->is_any_input_pin_high(pin_mask_);
}

}
