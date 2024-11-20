cmake_minimum_required(VERSION 3.18)

set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)
set(CMAKE_OBJCOPY arm-none-eabi-objcopy)
set(CMAKE_OBJDUMP arm-none-eabi-objdump)
set(CMAKE_SIZE arm-none-eabi-size)

set(CMAKE_CXX_STANDARD 23)

set(arch_flags
  -mcpu=cortex-m33
  -mfpu=auto
  -fshort-enums
  -specs=nano.specs
  -specs=nosys.specs
)

set(c_flags
  ${arch_flags}
  -Os  #optimization level
  -ggdb3
  -ffunction-sections
  -fdata-sections
  -fdiagnostics-color=always  # enable color output of compiler
)
string(REPLACE ";" " " c_flags_string "${c_flags}")
set(CMAKE_C_FLAGS "${c_flags_string}")
SET(CMAKE_ASM_FLAGS "${CMAKE_C_FLAGS}")

set(cxx_flags
  ${c_flags}
  
  -fno-exceptions
  -fno-rtti
 # -nostartfiles
 # -lcrt0-semihost
 # -lsemihost
)
string(REPLACE ";" " " cxx_flags_string "${cxx_flags}")
set(CMAKE_CXX_FLAGS "${cxx_flags_string}")

project(Demo CXX C ASM)

add_executable(${PROJECT_NAME}.elf
  main.cpp
  startup_stm32u575xx.S
)

add_compile_definitions(${PROJECT_NAME}.elf
  STM32U5
  STM32U575xx)

set(CMAKE_EXE_LINKER_FLAGS "-T ${CMAKE_CURRENT_SOURCE_DIR}/STM32U575ZITXQ_FLASH.ld -Wl,-Map=${PROJECT_NAME}.map")

target_link_libraries(${PROJECT_NAME}.elf
  DirectHal)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD COMMAND ${CMAKE_SIZE} --format=berkeley ${PROJECT_NAME}.elf)
add_custom_target(${PROJECT_NAME}.hex ALL DEPENDS ${PROJECT_NAME}.elf COMMAND ${CMAKE_OBJCOPY} -Oihex ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex)
add_custom_target(${PROJECT_NAME}.bin ALL DEPENDS ${PROJECT_NAME}.elf COMMAND ${CMAKE_OBJCOPY} -Obinary ${PROJECT_NAME}.elf ${PROJECT_NAME}.bin)

add_subdirectory(../../ hal)
