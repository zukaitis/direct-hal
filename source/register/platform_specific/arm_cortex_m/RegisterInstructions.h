#pragma once

extern "C" {
#include "cmsis_compiler.h"
}

namespace hal_impl {

inline void set_register_bit(uint32_t volatile& reg, uint32_t const bit_mask) {
  bool success {false};
  while (not success) {
    uint32_t const value = __LDREXW(&reg) | bit_mask;
    success = (0U == __STREXW(value, &reg));
  }
}

inline void reset_register_bit(uint32_t volatile& reg, uint32_t const bit_mask) {
  bool success {false};
  while (not success) {
    uint32_t const value = __LDREXW(&reg) & (~bit_mask);
    success = (0U == __STREXW(value, &reg));
  }
}

inline void modify_register_value(uint32_t volatile& reg, uint32_t const clear_mask, uint32_t const set_mask) {
  bool success {false};
  uint32_t const inverted_clear_mask {~clear_mask};
  while (not success) {
    uint32_t const value = (__LDREXW(&reg) & inverted_clear_mask) | set_mask;
    success = (0U == __STREXW(value, &reg));
  }
}

}
