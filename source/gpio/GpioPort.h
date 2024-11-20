#pragma once

#include "hal/gpio/GpioConfiguration.h"

#include "register/Register.h"

namespace hal_impl {

class GpioPort {
 public:

  inline void configure_pin_as_input(hal::GpioPin const pin) {
    configure_pin_mode(pin, GpioMode::kInput);
  }

  inline void configure_pin_as_output(hal::GpioPin const pin) {
    configure_pin_mode(pin, GpioMode::kOutput);
  }

  inline void configure_pin_as_alternate_function(hal::GpioPin const pin, hal::GpioAlternateFunction const alternate_function) {
    configure_pin_mode(pin, GpioMode::kAlternateFunction);
    set_alternate_function(pin, alternate_function);
  }

  inline void configure_pin_as_analog(hal::GpioPin const pin) {
    configure_pin_mode(pin, GpioMode::kAnalog);
  }

  inline void set_output_type(hal::GpioPin const pin, hal::OutputType const type) {
    uint8_t const bit_index {std::to_underlying(pin)};
    SingleBit const bit {kSingleBit[bit_index]};
  
    if (hal::OutputType::kPushPull == type) {
      otyper_.reset_bit(bit);
    } else {
      otyper_.set_bit(bit);
    }
  }

  inline void set_output_speed(hal::GpioPin const pin, hal::OutputSpeed const speed) {
    uint8_t const range_index {std::to_underlying(pin)};
    BitRange const bit_range {k2BitRange[range_index]};
  
    ospeedr_.set_bit_range_value(bit_range, std::to_underlying(speed));
  }

  inline void set_pupd(hal::GpioPin const pin, hal::Pupd const pupd) {
    uint8_t const range_index {std::to_underlying(pin)};
    BitRange const bit_range {k2BitRange[range_index]};
  
    pupdr_.set_bit_range_value(bit_range, std::to_underlying(pupd));
  }

  inline bool is_input_pin_high(hal::GpioPin const pin) {
    return idr_.is_bit_set(kSingleBit[std::to_underlying(pin)]);
  }

  inline bool is_output_pin_high(hal::GpioPin const pin) {
    return odr_.is_bit_set(kSingleBit[std::to_underlying(pin)]);
  }

  inline void set_pin_high(hal::GpioPin const pin) {
    bsrr_.set_value(kSingleBit[std::to_underlying(pin)].get_mask());
  }

  inline void set_pin_low(hal::GpioPin const pin) {
    brr_.set_value(kSingleBit[std::to_underlying(pin)].get_mask());
  }

 private:
  // Instances of this class shouldn't be created
  GpioPort() = default;
  ~GpioPort() = default;

  enum class GpioMode : uint8_t {
    kInput = 0U,
    kOutput = 1U,
    kAlternateFunction = 2U,
    kAnalog = 3U,
  };

  inline void configure_pin_mode(hal::GpioPin const pin, GpioMode const mode) {
    uint8_t const range_index {std::to_underlying(pin)};
    BitRange const bit_range {k2BitRange[range_index]};
  
    moder_.set_bit_range_value(bit_range, std::to_underlying(mode));
  }

  inline void set_alternate_function(hal::GpioPin const pin, hal::GpioAlternateFunction const alternate_function) {
    static constexpr uint8_t kPinsPerRegister {8U};
    int const register_index {std::to_underlying(pin) / kPinsPerRegister};
    int const range_index {std::to_underlying(pin) % kPinsPerRegister};
    BitRange const bit_range {k4BitRange[range_index]};
  
    afr_[register_index].set_bit_range_value(bit_range, std::to_underlying(alternate_function));
  }

  Register moder_;
  Register otyper_;
  Register ospeedr_;
  Register pupdr_;
  Register idr_;
  Register odr_;
  Register bsrr_;
  Register lckr_;
  std::array<Register, 2U> afr_;
  Register brr_;
  Register hslvr_;
  Register seccfgr_;
};

}
