/* Copyright (c) 2017-2022, Hans Erik Thrane */

/* !!! THIS FILE HAS BEEN AUTO-GENERATED !!! */

#pragma once

#include <fmt/chrono.h>
#include <fmt/format.h>

#include <chrono>
#include <string_view>

#include "roq/numbers.hpp"
#include "roq/span.hpp"
#include "roq/string_types.hpp"
#include "roq/uuid.hpp"

namespace roq {

//! A single measurement point
struct ROQ_PUBLIC Measurement final {
  MeasurementKey name;  //!< Key
  double value = NaN;   //!< Value
};

}  // namespace roq

template <>
struct fmt::formatter<roq::Measurement> {
  template <typename Context>
  constexpr auto parse(Context &context) {
    return std::begin(context);
  }
  template <typename Context>
  auto format(roq::Measurement const &value, Context &context) {
    using namespace std::literals;
    return fmt::format_to(
        context.out(),
        R"({{)"
        R"(name="{}", )"
        R"(value={})"
        R"(}})"sv,
        value.name,
        value.value);
  }
};
