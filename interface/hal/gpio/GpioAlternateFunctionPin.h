#pragma once

#include "GpioConfiguration.h"

namespace hal {

class GpioAlternateFunctionPin {
 public:
  constexpr GpioAlternateFunctionPin(GpioPort const port, GpioPin const pin) :
    port_ {port},
    pin_ {pin}
  {
  }
  ~GpioAlternateFunctionPin() = default;

  void configure(GpioAlternateFunction const alternate_function) const;

  void configure(Pupd const pupd_configuration) const;

 private:
  GpioPort port_;
  GpioPin pin_;
};

}