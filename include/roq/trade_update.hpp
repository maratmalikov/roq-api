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

#include "roq/fill.hpp"
#include "roq/position_effect.hpp"
#include "roq/side.hpp"
#include "roq/update_type.hpp"

namespace roq {

//! Update relating to order being partially or fully filled
struct ROQ_PUBLIC TradeUpdate final {
  uint16_t stream_id = {};                        //!< Stream identifier
  std::string_view account;                       //!< Account name
  uint32_t order_id = {};                         //!< Order identifier
  std::string_view exchange;                      //!< Exchange
  std::string_view symbol;                        //!< Symbol
  Side side = {};                                 //!< Side
  PositionEffect position_effect = {};            //!< Position effect
  std::chrono::nanoseconds create_time_utc = {};  //!< Created timestamp (UTC)
  std::chrono::nanoseconds update_time_utc = {};  //!< Updated timestamp (UTC)
  std::string_view external_account;              //!< External account name
  std::string_view external_order_id;             //!< External order identifier
  std::span<Fill> fills;                          //!< List of fills
  std::string_view routing_id;                    //!< Routing identifier
  UpdateType update_type = {};                    //!< Update type
};

template <>
inline constexpr std::string_view get_name<TradeUpdate>() {
  using namespace std::literals;
  return "trade_update"sv;
}

}  // namespace roq

template <>
struct fmt::formatter<roq::TradeUpdate> {
  template <typename Context>
  constexpr auto parse(Context &context) {
    return std::begin(context);
  }
  template <typename Context>
  auto format(roq::TradeUpdate const &value, Context &context) {
    using namespace std::literals;
    return fmt::format_to(
        context.out(),
        R"({{)"
        R"(stream_id={}, )"
        R"(account="{}", )"
        R"(order_id={}, )"
        R"(exchange="{}", )"
        R"(symbol="{}", )"
        R"(side={}, )"
        R"(position_effect={}, )"
        R"(create_time_utc={}, )"
        R"(update_time_utc={}, )"
        R"(external_account="{}", )"
        R"(external_order_id="{}", )"
        R"(fills=[{}], )"
        R"(routing_id="{}", )"
        R"(update_type={})"
        R"(}})"sv,
        value.stream_id,
        value.account,
        value.order_id,
        value.exchange,
        value.symbol,
        value.side,
        value.position_effect,
        value.create_time_utc,
        value.update_time_utc,
        value.external_account,
        value.external_order_id,
        fmt::join(value.fills, ", "sv),
        value.routing_id,
        value.update_type);
  }
};

template <>
struct fmt::formatter<roq::Event<roq::TradeUpdate> > {
  template <typename Context>
  constexpr auto parse(Context &context) {
    return std::begin(context);
  }
  template <typename Context>
  auto format(roq::Event<roq::TradeUpdate> const &event, Context &context) {
    using namespace std::literals;
    return fmt::format_to(
        context.out(),
        R"({{)"
        R"(trade_update={}, )"
        R"(message_info={})"
        R"(}})"sv,
        event.value,
        event.message_info);
  }
};

template <>
struct fmt::formatter<roq::Trace<roq::TradeUpdate const> > {
  template <typename Context>
  constexpr auto parse(Context &context) {
    return std::begin(context);
  }
  template <typename Context>
  auto format(roq::Trace<roq::TradeUpdate const> const &event, Context &context) {
    using namespace std::literals;
    return fmt::format_to(
        context.out(),
        R"({{)"
        R"(trade_update={}, )"
        R"(trace_info={})"
        R"(}})"sv,
        event.value,
        event.trace_info);
  }
};
