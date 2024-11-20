#pragma once

#include <cstdint>

namespace hal {

enum class GpioPort : uint8_t {
  kA = 0U,
  kB,
  kC,
  kD,
  kE,
  kF,
  kG,
  kH,
  kI,
  kJ,
  kLpgpio,
};

enum class GpioPin : uint8_t {
  k0 = 0U,
  k1,
  k2,
  k3,
  k4,
  k5,
  k6,
  k7,
  k8,
  k9,
  k10,
  k11,
  k12,
  k13,
  k14,
  k15,
};

enum class GpioAlternateFunction : uint8_t {
  k0 = 0U,
  k1,
  k2,
  k3,
  k4,
  k5,
  k6,
  k7,
  k8,
  k9,
  k10,
  k11,
  k12,
  k13,
  k14,
  k15,
};

enum class OutputType : uint8_t {
  kPushPull = 0U,
  kOpenDrain,
};

enum class OutputSpeed : uint8_t {
  kLow = 0U,
  kMedium,
  kHigh,
  kVeryHigh,
};

enum class Pupd : uint8_t {
  kNoPull = 0U,
  kPullUp,
  kPullDown,
};

struct GpioOutputConfiguration {
  OutputType output_type;
  OutputSpeed output_speed;
  Pupd pupd;
};

}
