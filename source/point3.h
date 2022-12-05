#pragma once
#include <type_traits>

template<typename T>
requires std::is_floating_point_v<T> || std::is_integral_v<T>
class point3 {
  point3() = default;
};
