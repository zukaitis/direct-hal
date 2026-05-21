#pragma once

#include "hal/gpio/GpioConfiguration.h"

#include "gpio/GpioPorts.h"
#include "hal/compilation_error.h"

namespace hal {

class GpioOutputPin {
 public:
  constexpr GpioOutputPin(GpioPort const port, GpioPin const pin) :
    port_registers_ {hal_impl::GpioPorts::get(port)},
    pin_mask_ {hal_impl::kSingleBit[std::to_underlying(pin)]},
    port_ {port},
    pin_ {pin}
  {
    if (std::is_constant_evaluated()) {
      if (not hal_impl::is_pin_available(port, pin)) {
        compilation_error("Pin unavailable on selected microcontroller");
      }
    }
  }

  ~GpioOutputPin() = default;

  void configure() const;

  void configure(GpioOutputConfiguration const& configuration) const;

  bool is_high() const;

  void set_high() const;

  void set_low() const;

  void toggle() const;
 private:
  hal_impl::RegisterSet<hal_impl::GpioPortRegisters> port_registers_;
  hal_impl::Mask pin_mask_;
  GpioPort port_;
  GpioPin pin_;
};

}
