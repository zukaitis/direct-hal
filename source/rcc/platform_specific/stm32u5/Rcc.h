#pragma once

#include "stm32u5xx.h"

#include <array>

namespace hal_impl {

class Rcc final {
 public:

  static inline Rcc& get() {
    return *reinterpret_cast<Rcc*>(RCC);
  }

  Register cr_;
  Register const reserved0_;
  Register icscr1_;
  Register icscr2_;
  Register icscr3_;
  Register crrcr_;
  Register const reserved1_;
  Register cfgr1_;
  Register cfgr2_;
  Register cfgr3_;
  Register pll1cfgr_;
  Register pll2cfgr_;
  Register pll3cfgr_;
  Register pll1divr_;
  Register pll1fracr_;
  Register pll2divr_;
  Register pll2fracr_;
  Register pll3divr_;
  Register pll3fracr_;
  Register const reserved2_;
  Register cier_;
  Register cifr_;
  Register cicr_;
  Register const reserved3_;
  Register ahb1rstr_;
  Register ahb2rstr1_;
  Register ahb2rstr2_;
  Register ahb3rstr_;
  Register const reserved4_;
  Register apb1rstr1_;
  Register apb1rstr2_;
  Register apb2rstr_;
  Register apb3rstr_;
  Register const reserved5_;
  Register ahb1enr_;
  Register ahb2enr1_;
  Register ahb2enr2_;
  Register ahb3enr_;
  Register const reserved6_;
  Register apb1enr1_;
  Register apb1enr2_;
  Register apb2enr_;
  Register apb3enr_;
  Register const reserved7_;
  Register ahb1smenr_;
  Register ahb2smenr1_;
  Register ahb2smenr2_;
  Register ahb3smenr_;
  Register const reserved8_;
  Register apb1smenr1_;
  Register apb1smenr2_;
  Register apb2smenr_;
  Register apb3smenr_;
  Register const reserved9_;
  Register srdamr_;
  Register const reserved10_;
  Register ccipr1_;
  Register ccipr2_;
  Register ccipr3_;
  Register const reserved11_;
  Register bdcr_;
  Register csr_;
  std::array<Register const, 6U> reserved12_;
  Register seccfgr_;
  Register privcfgr_;

 private:
  // Instances of this class shouldn't be created
  Rcc() = default;
  ~Rcc() = default;

};

}
