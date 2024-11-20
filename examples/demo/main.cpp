#include "hal/gpio/GpioInputPin.h"
#include "hal/gpio/GpioOutputPin.h"

static constexpr hal::GpioInputPin kInputButton {hal::GpioPort::kC, hal::GpioPin::k13};
static constexpr hal::GpioOutputPin kOutputLed {hal::GpioPort::kB, hal::GpioPin::k7};

int main() {
  kInputButton.configure();
  kOutputLed.configure();
  while (true) {
    if (kInputButton.is_high()) {
      kOutputLed.set_high();
    } else {
      kOutputLed.set_low();
    }
  }
  return 0;
}

extern "C" void SystemInit (void)
{
#if defined (__VTOR_PRESENT) && (__VTOR_PRESENT == 1U)
  SCB->VTOR = (uint32_t) &(__VECTOR_TABLE[0]);
#endif
}
