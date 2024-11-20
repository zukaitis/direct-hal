#pragma once

#include "GpioConfiguration.h"

namespace hal {

class GpioInputPin {
 public:
  constexpr GpioInputPin(GpioPort const port, GpioPin const pin) :
    port_ {port},
    pin_ {pin}
  {
  }
  ~GpioInputPin() = default;

  void configure() const;

  void configure(Pupd const pupd_configuration) const;

  bool is_high() const;
 private:
  GpioPort const port_;
  GpioPin const pin_;
};

}
