
add_library(DirectHal STATIC
  source/gpio/GpioAlternateFunctionPin.cpp
  source/gpio/GpioInputPin.cpp
  source/gpio/GpioOutputPin.cpp
)

target_include_directories(DirectHal PUBLIC
  interface
)

target_include_directories(DirectHal PRIVATE
  source
  source/configuration
  third_party/cmsis-core/Include
  third_party/cmsis-device-u5/Include
)
