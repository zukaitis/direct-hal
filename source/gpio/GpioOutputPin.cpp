#include "hal/gpio/GpioOutputPin.h"

#include "GpioPorts.h"

namespace hal {

void GpioOutputPin::configure() const {
  hal_impl::GpioPorts::enable_peripheral_clock(port_);
  port_registers_->configure_pin_as_output(pin_);
}

void GpioOutputPin::configure(GpioOutputConfiguration const& configuration) const {
  configure();
  port_registers_->set_output_type(pin_, configuration.output_type);
  port_registers_->set_output_speed(pin_, configuration.output_speed);
  port_registers_->set_pupd(pin_, configuration.pupd);
}

bool GpioOutputPin::is_high() const {
  return port_registers_->is_any_output_pin_high(pin_mask_);
}

void GpioOutputPin::set_high() const {
  port_registers_->set_pins_high(pin_mask_);
}

void GpioOutputPin::set_low() const {
  port_registers_->set_pins_low(pin_mask_);
}

void GpioOutputPin::toggle() const {
  if (is_high()) {
    set_low();
  } else {
    set_high();
  }
}

}