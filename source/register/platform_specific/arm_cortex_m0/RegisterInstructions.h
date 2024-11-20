#pragma once

namespace hal_impl {

inline void set_register_bit(uint32_t volatile& reg, uint32_t const bit_mask) {
  reg |= bit_mask;
}

inline void reset_register_bit(uint32_t volatile& reg, uint32_t const bit_mask) {
  reg &= (~bit_mask);
}

inline void modify_register_value(uint32_t volatile& reg, uint32_t const clear_mask, uint32_t const set_mask) {
  uint32_t const inverted_clear_mask {~clear_mask};
  reg = (reg & inverted_clear_mask) | set_mask;
}

}
