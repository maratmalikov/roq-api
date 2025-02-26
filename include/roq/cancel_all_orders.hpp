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

//! Fields required to cancel all orders
struct ROQ_PUBLIC CancelAllOrders final {
  std::string_view account;  //!< Account name
};

template <>
inline constexpr std::string_view get_name<CancelAllOrders>() {
  using namespace std::literals;
  return "cancel_all_orders"sv;
}

}  // namespace roq

template <>
struct fmt::formatter<roq::CancelAllOrders> {
  template <typename Context>
  constexpr auto parse(Context &context) {
    return std::begin(context);
  }
  template <typename Context>
  auto format(roq::CancelAllOrders const &value, Context &context) {
    using namespace std::literals;
    return fmt::format_to(
        context.out(),
        R"({{)"
        R"(account="{}")"
        R"(}})"sv,
        value.account);
  }
};

template <>
struct fmt::formatter<roq::Event<roq::CancelAllOrders> > {
  template <typename Context>
  constexpr auto parse(Context &context) {
    return std::begin(context);
  }
  template <typename Context>
  auto format(roq::Event<roq::CancelAllOrders> const &event, Context &context) {
    using namespace std::literals;
    return fmt::format_to(
        context.out(),
        R"({{)"
        R"(cancel_all_orders={}, )"
        R"(message_info={})"
        R"(}})"sv,
        event.value,
        event.message_info);
  }
};

template <>
struct fmt::formatter<roq::Trace<roq::CancelAllOrders const> > {
  template <typename Context>
  constexpr auto parse(Context &context) {
    return std::begin(context);
  }
  template <typename Context>
  auto format(roq::Trace<roq::CancelAllOrders const> const &event, Context &context) {
    using namespace std::literals;
    return fmt::format_to(
        context.out(),
        R"({{)"
        R"(cancel_all_orders={}, )"
        R"(trace_info={})"
        R"(}})"sv,
        event.value,
        event.trace_info);
  }
};
