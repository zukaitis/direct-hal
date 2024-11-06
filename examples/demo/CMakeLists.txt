cmake_minimum_required(VERSION 3.18)

set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

set(cxx_flags
--target=thumbv8m.main-unknown-none-eabi
  -std=c++23
  -mfpu=none
  -fno-exceptions
  -fno-rtti
  -nostartfiles
  -lcrt0-semihost
  -lsemihost
)
string(REPLACE ";" " " cxx_flags_string "${cxx_flags}")
set(CMAKE_CXX_FLAGS "${cxx_flags_string}")

project(Demo)

add_executable(Demo
  main.cpp
  startup_stm32u5a5xx.s
)

add_compile_definitions(Demo
  STM32U575xx)

add_link_options(Demo
  "-T STM32U575ZITXQ_FLASH.ld")

target_link_libraries(Demo
  DirectHal)

add_subdirectory(../../ hal)
