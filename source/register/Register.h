#pragma once

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

class SingleBit {
 public:
  constexpr explicit SingleBit(Bit const bit) :
    mask_ {1U << std::to_underlying(bit)}
  {
  }
  
  ~SingleBit() = default;

  constexpr inline uint32_t get_mask() const {
    return mask_;
  }

 private:
  uint32_t mask_;
};

class BitRange {
 public:
  constexpr BitRange(Bit const high_bit, Bit const low_bit) :
    bit_mask_ {((1U << (std::to_underlying(high_bit) - std::to_underlying(low_bit) + 1U)) - 1U) << std::to_underlying(low_bit)},
    bit_shift_ {std::to_underlying(low_bit)}
  {
  }

  virtual ~BitRange() = default;

  constexpr inline uint32_t get_bit_mask() const {
    return bit_mask_;
  }

  constexpr inline uint32_t get_bit_shift() const {
    return bit_shift_;
  }

 private:
  uint32_t bit_mask_;
  uint32_t bit_shift_;
};

class Register {
 public:
  Register() = default;
  virtual ~Register() = default;

  inline void set_value(uint32_t const value) {
    register_ = value;
  }

  inline uint32_t get_value() const {
    return register_;
  }

  inline void set_bit(SingleBit const bit) {
    register_ |= bit.get_mask();
  }

  inline void reset_bit(SingleBit const bit) {
    register_ &= ~(bit.get_mask());
  }

  inline bool is_bit_set(SingleBit const bit) const {
    return (0U != (register_ & bit.get_mask()));
  }

  inline void set_bit_range_value(BitRange const bit_range, uint32_t const value) {
    uint32_t const clear_mask {~bit_range.get_bit_mask()};
    uint32_t const shifted_value {(value << bit_range.get_bit_shift()) & bit_range.get_bit_mask()};
    register_ = (register_ & clear_mask) | shifted_value;
  }

  inline uint32_t get_bit_range_value(BitRange const bit_range) const {
    return (register_ & bit_range.get_bit_mask()) >> bit_range.get_bit_shift();
  }

 private:
  volatile uint32_t register_;
};

constexpr std::array<SingleBit, 32U> kSingleBit {
  SingleBit(Bit::k0),
  SingleBit(Bit::k1),
  SingleBit(Bit::k2),
  SingleBit(Bit::k3),
  SingleBit(Bit::k4),
  SingleBit(Bit::k5),
  SingleBit(Bit::k6),
  SingleBit(Bit::k7),
  SingleBit(Bit::k8),
  SingleBit(Bit::k9),
  SingleBit(Bit::k10),
  SingleBit(Bit::k11),
  SingleBit(Bit::k12),
  SingleBit(Bit::k13),
  SingleBit(Bit::k14),
  SingleBit(Bit::k15),
  SingleBit(Bit::k16),
  SingleBit(Bit::k17),
  SingleBit(Bit::k18),
  SingleBit(Bit::k19),
  SingleBit(Bit::k20),
  SingleBit(Bit::k21),
  SingleBit(Bit::k22),
  SingleBit(Bit::k23),
  SingleBit(Bit::k24),
  SingleBit(Bit::k25),
  SingleBit(Bit::k26),
  SingleBit(Bit::k27),
  SingleBit(Bit::k28),
  SingleBit(Bit::k29),
  SingleBit(Bit::k30),
  SingleBit(Bit::k31),
};

constexpr std::array<BitRange, 16U> k2BitRange {
  BitRange(Bit::k1, Bit::k0),
  BitRange(Bit::k3, Bit::k2),
  BitRange(Bit::k5, Bit::k4),
  BitRange(Bit::k7, Bit::k6),
  BitRange(Bit::k9, Bit::k8),
  BitRange(Bit::k11, Bit::k10),
  BitRange(Bit::k13, Bit::k12),
  BitRange(Bit::k15, Bit::k14),
  BitRange(Bit::k17, Bit::k16),
  BitRange(Bit::k19, Bit::k18),
  BitRange(Bit::k21, Bit::k20),
  BitRange(Bit::k23, Bit::k22),
  BitRange(Bit::k25, Bit::k24),
  BitRange(Bit::k27, Bit::k26),
  BitRange(Bit::k29, Bit::k28),
  BitRange(Bit::k31, Bit::k30),
};

constexpr std::array<BitRange, 8U> k4BitRange {
  BitRange(Bit::k3, Bit::k0),
  BitRange(Bit::k7, Bit::k4),
  BitRange(Bit::k11, Bit::k8),
  BitRange(Bit::k15, Bit::k12),
  BitRange(Bit::k19, Bit::k16),
  BitRange(Bit::k23, Bit::k20),
  BitRange(Bit::k27, Bit::k24),
  BitRange(Bit::k31, Bit::k28),
};

constexpr std::array<BitRange, 4U> k8BitRange {
  BitRange(Bit::k7, Bit::k0),
  BitRange(Bit::k15, Bit::k8),
  BitRange(Bit::k23, Bit::k16),
  BitRange(Bit::k31, Bit::k24),
};

}
