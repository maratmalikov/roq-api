/* Copyright (c) 2017-2022, Hans Erik Thrane */

/* !!! THIS FILE HAS BEEN AUTO-GENERATED !!! */

#pragma once

#include <fmt/format.h>

#include <cassert>

namespace roq {

//! Enumeration of execution types
enum class ExecutionInstruction : uint32_t {
  UNDEFINED = 0x0,
  PARTICIPATE_DO_NOT_INITIATE = 0x1,  //!< Cancel if order would have executed on placement (i.e. not as maker)
  CANCEL_IF_NOT_BEST = 0x2,           //!< Cancel if order can not be placed at best price
  DO_NOT_INCREASE =
      0x4,              //!< Order may only reduce net position, order quantity can automatically be reduced by exchange
  DO_NOT_REDUCE = 0x8,  //!< Order can not be partially filled, aka. all-or-none (AON) orders
};

}  // namespace roq

template <>
struct fmt::formatter<roq::ExecutionInstruction> {
  template <typename Context>
  constexpr auto parse(Context &context) {
    return std::begin(context);
  }
  template <typename Context>
  auto format(roq::ExecutionInstruction const &value, Context &context) {
    using namespace std::literals;
#if __cplusplus >= 202002L
    std::string_view name{[&]() {
      switch (value) {
        using enum roq::ExecutionInstruction;
        case UNDEFINED:
          return "UNDEFINED"sv;
        case PARTICIPATE_DO_NOT_INITIATE:
          return "PARTICIPATE_DO_NOT_INITIATE"sv;
        case CANCEL_IF_NOT_BEST:
          return "CANCEL_IF_NOT_BEST"sv;
        case DO_NOT_INCREASE:
          return "DO_NOT_INCREASE"sv;
        case DO_NOT_REDUCE:
          return "DO_NOT_REDUCE"sv;
        default:
          assert(false);
      }
      return "<UNKNOWN>"sv;
    }()};
#else
    std::string_view name{[&]() {
      switch (value) {
        case roq::ExecutionInstruction::UNDEFINED:
          return "UNDEFINED"sv;
        case roq::ExecutionInstruction::PARTICIPATE_DO_NOT_INITIATE:
          return "PARTICIPATE_DO_NOT_INITIATE"sv;
        case roq::ExecutionInstruction::CANCEL_IF_NOT_BEST:
          return "CANCEL_IF_NOT_BEST"sv;
        case roq::ExecutionInstruction::DO_NOT_INCREASE:
          return "DO_NOT_INCREASE"sv;
        case roq::ExecutionInstruction::DO_NOT_REDUCE:
          return "DO_NOT_REDUCE"sv;
        default:
          assert(false);
      }
      return "<UNKNOWN>"sv;
    }()};
#endif
    return fmt::format_to(context.out(), "{}"sv, name);
  }
};
