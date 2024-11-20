#pragma once

#include "GpioConfiguration.h"

namespace hal {

class GpioOutputPin {
 public:
  constexpr GpioOutputPin(GpioPort const port, GpioPin const pin) :
    port_ {port},
    pin_ {pin}
  {
  }
  ~GpioOutputPin() = default;

  void configure() const;

  void configure(GpioOutputConfiguration const& configuration) const;

  bool is_high() const;

  void set_high() const;

  void set_low() const;
 private:
  GpioPort port_;
  GpioPin pin_;
};

}