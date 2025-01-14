/* Copyright (c) 2017-2022, Hans Erik Thrane */

/* !!! THIS FILE HAS BEEN AUTO-GENERATED !!! */

#pragma once

#include <fmt/chrono.h>
#include <fmt/format.h>

#include <chrono>
#include <string_view>

#include "roq/compat.hpp"
#include "roq/event.hpp"
#include "roq/mask.hpp"
#include "roq/message_info.hpp"
#include "roq/name.hpp"
#include "roq/numbers.hpp"
#include "roq/span.hpp"
#include "roq/string_types.hpp"
#include "roq/trace.hpp"

namespace roq {

//! Identifies the beginning of a sequence of related messages
struct ROQ_PUBLIC BatchBegin final {};

template <>
inline constexpr std::string_view get_name<BatchBegin>() {
  using namespace std::literals;
  return "batch_begin"sv;
}

}  // namespace roq

template <>
struct fmt::formatter<roq::BatchBegin> {
  template <typename Context>
  constexpr auto parse(Context &context) {
    return std::begin(context);
  }
  template <typename Context>
  auto format(roq::BatchBegin const &, Context &context) {
    using namespace std::literals;
    return fmt::format_to(context.out(), R"({{}})"sv);
  }
};

template <>
struct fmt::formatter<roq::Event<roq::BatchBegin> > {
  template <typename Context>
  constexpr auto parse(Context &context) {
    return std::begin(context);
  }
  template <typename Context>
  auto format(roq::Event<roq::BatchBegin> const &event, Context &context) {
    using namespace std::literals;
    return fmt::format_to(
        context.out(),
        R"({{)"
        R"(batch_begin={}, )"
        R"(message_info={})"
        R"(}})"sv,
        event.value,
        event.message_info);
  }
};

template <>
struct fmt::formatter<roq::Trace<roq::BatchBegin const> > {
  template <typename Context>
  constexpr auto parse(Context &context) {
    return std::begin(context);
  }
  template <typename Context>
  auto format(roq::Trace<roq::BatchBegin const> const &event, Context &context) {
    using namespace std::literals;
    return fmt::format_to(
        context.out(),
        R"({{)"
        R"(batch_begin={}, )"
        R"(trace_info={})"
        R"(}})"sv,
        event.value,
        event.trace_info);
  }
};
