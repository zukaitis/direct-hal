#pragma once

#include <string_view>

namespace hal {

/* This function is not supposed to do anything. It's not constexpr by design,
so compilation error would be thrown when it appears inside std::is_constant_evaluated() tree and a check */
static void compilation_error(std::string_view) {
}

}  // namespace hal
