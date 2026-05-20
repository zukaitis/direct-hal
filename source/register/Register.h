#pragma once

#if defined(STM32U5)
#include "register/platform_specific/arm_cortex_m/RegisterInstructions.h"
#else
#error Platform unspecified or not supported
#endif

#include <array>
#include <cstdint>
#include <utility>

namespace hal_impl {

enum class Bit : uint8_t {
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
  k16,
  k17,
  k18,
  k19,
  k20,
  k21,
  k22,
  k23,
  k24,
  k25,
  k26,
  k27,
  k28,
  k29,
  k30,
  k31,
};

class Mask {
 public:
  constexpr explicit Mask(uint32_t const mask) :
    mask_ {mask}
  {
  }

  constexpr explicit Mask(Bit const bit) :
    mask_ {1U << std::to_underlying(bit)}
  {
  }

  constexpr inline uint32_t get_mask() const {
    return mask_;
  }

 protected:
  uint32_t mask_;
};

constexpr std::array<Mask, 32U> kSingleBit {
  Mask(Bit::k0),
  Mask(Bit::k1),
  Mask(Bit::k2),
  Mask(Bit::k3),
  Mask(Bit::k4),
  Mask(Bit::k5),
  Mask(Bit::k6),
  Mask(Bit::k7),
  Mask(Bit::k8),
  Mask(Bit::k9),
  Mask(Bit::k10),
  Mask(Bit::k11),
  Mask(Bit::k12),
  Mask(Bit::k13),
  Mask(Bit::k14),
  Mask(Bit::k15),
  Mask(Bit::k16),
  Mask(Bit::k17),
  Mask(Bit::k18),
  Mask(Bit::k19),
  Mask(Bit::k20),
  Mask(Bit::k21),
  Mask(Bit::k22),
  Mask(Bit::k23),
  Mask(Bit::k24),
  Mask(Bit::k25),
  Mask(Bit::k26),
  Mask(Bit::k27),
  Mask(Bit::k28),
  Mask(Bit::k29),
  Mask(Bit::k30),
  Mask(Bit::k31),
};


class BitRange : public Mask {
 public:
  constexpr BitRange(Bit const low_bit, Bit const high_bit) :
    Mask {((1U << (std::to_underlying(high_bit) - std::to_underlying(low_bit) + 1U)) - 1U) << std::to_underlying(low_bit)},
    bit_shift_ {std::to_underlying(low_bit)}
  {
  }

  constexpr inline uint32_t get_bit_shift() const {
    return bit_shift_;
  }

 private:
  uint32_t bit_shift_;
};

constexpr std::array<BitRange, 16U> k2BitRange {
  BitRange(Bit::k0, Bit::k1),
  BitRange(Bit::k2, Bit::k3),
  BitRange(Bit::k4, Bit::k5),
  BitRange(Bit::k6, Bit::k7),
  BitRange(Bit::k8, Bit::k9),
  BitRange(Bit::k10, Bit::k11),
  BitRange(Bit::k12, Bit::k13),
  BitRange(Bit::k14, Bit::k15),
  BitRange(Bit::k16, Bit::k17),
  BitRange(Bit::k18, Bit::k19),
  BitRange(Bit::k20, Bit::k21),
  BitRange(Bit::k22, Bit::k23),
  BitRange(Bit::k24, Bit::k25),
  BitRange(Bit::k26, Bit::k27),
  BitRange(Bit::k28, Bit::k29),
  BitRange(Bit::k30, Bit::k31),
};

constexpr std::array<BitRange, 8U> k4BitRange {
  BitRange(Bit::k0, Bit::k3),
  BitRange(Bit::k4, Bit::k7),
  BitRange(Bit::k8, Bit::k11),
  BitRange(Bit::k12, Bit::k15),
  BitRange(Bit::k16, Bit::k19),
  BitRange(Bit::k20, Bit::k23),
  BitRange(Bit::k24, Bit::k27),
  BitRange(Bit::k28, Bit::k31),
};

constexpr std::array<BitRange, 4U> k8BitRange {
  BitRange(Bit::k0, Bit::k7),
  BitRange(Bit::k8, Bit::k15),
  BitRange(Bit::k16, Bit::k23),
  BitRange(Bit::k24, Bit::k31),
};


class Register final {
 public:

  inline void set_value(uint32_t const value) {
    register_ = value;
  }

  inline uint32_t get_value() const {
    return register_;
  }

  inline void set_bits(Mask const mask) {
    // set_register_bit(register_, mask.get_mask());
  }

  inline void reset_bits(Mask const mask) {
    reset_register_bit(register_, mask.get_mask());
  }

  inline bool is_any_bit_set(Mask const mask) const {
    return (0U != (register_ & mask.get_mask()));
  }

  inline void set_bit_range_value(BitRange const bit_range, uint32_t const value) {
    uint32_t const clear_mask {bit_range.get_mask()};
    uint32_t const shifted_value {(value << bit_range.get_bit_shift()) & bit_range.get_mask()};
    modify_register_value(register_, clear_mask, shifted_value);  
  }

  inline uint32_t get_bit_range_value(BitRange const bit_range) const {
    return (register_ & bit_range.get_mask()) >> bit_range.get_bit_shift();
  }

 private:
  // Instances of this class shouldn't be created
  Register() = default;
  ~Register() = default;

  uint32_t volatile register_;
};


}
