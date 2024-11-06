#include "hal/gpio/GpioInputPin.h"

#include <utility>

static constexpr hal::GpioInputPin varpas {hal::GpioPort::kA, hal::GpioPin::k7};

int main() {
  varpas.configure();
  std::ignore = varpas.is_high();
  return 0;
}
