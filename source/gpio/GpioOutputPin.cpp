#include "hal/gpio/GpioOutputPin.h"

#include "GpioPorts.h"

namespace hal {

void GpioOutputPin::configure() const {
  hal_impl::GpioPorts::enable_peripheral_clock(port_);
  hal_impl::GpioPorts::get(port_).configure_pin_as_output(pin_);
}

void GpioOutputPin::configure(GpioOutputConfiguration const& configuration) const {
  configure();
  hal_impl::GpioPort& port {hal_impl::GpioPorts::get(port_)};
  port.set_output_type(pin_, configuration.output_type);
  port.set_output_speed(pin_, configuration.output_speed);
  port.set_pupd(pin_, configuration.pupd);
}

bool GpioOutputPin::is_high() const {
  return hal_impl::GpioPorts::get(port_).is_output_pin_high(pin_);
}

void GpioOutputPin::set_high() const {
  hal_impl::GpioPorts::get(port_).set_pin_high(pin_);
}

void GpioOutputPin::set_low() const {
  hal_impl::GpioPorts::get(port_).set_pin_low(pin_);
}

}