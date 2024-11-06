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

  bool is_high() const;
 private:
  GpioPort port_;
  GpioPin pin_;
};

}
