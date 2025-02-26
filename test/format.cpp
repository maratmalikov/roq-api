/* Copyright (c) 2017-2022, Hans Erik Thrane */

#include <catch2/catch_all.hpp>

#include "roq/market_by_price_update.hpp"
#include "roq/side.hpp"

using namespace roq;

using namespace std::literals;

TEST_CASE("format_Side", "[format]") {
  CHECK(fmt::format("{}"sv, Side{Side::UNDEFINED}) == "UNDEFINED"sv);
  CHECK(fmt::format("{}"sv, Side{Side::BUY}) == "BUY"sv);
  CHECK(fmt::format("{}"sv, Side{Side::SELL}) == "SELL"sv);
}

TEST_CASE("format_market_by_price", "[format]") {
  roq::MBPUpdate bids[] = {
      {.price = 1.0, .quantity = 2.0, .implied_quantity = 3.0, .price_level = 1, .number_of_orders = 2},
      {.price = 2.0, .quantity = 4.0, .implied_quantity = 3.0, .price_level = 1, .number_of_orders = 2},
      {.price = 3.0, .quantity = 8.0, .implied_quantity = 3.0, .price_level = 1, .number_of_orders = 2},
      {.price = 4.0, .quantity = 10.0, .implied_quantity = 3.0, .price_level = 1, .number_of_orders = 2},
      {.price = 5.0, .quantity = 12.0, .implied_quantity = 3.0, .price_level = 1, .number_of_orders = 2},
  };
  roq::MBPUpdate asks[] = {
      {.price = 1.0, .quantity = 2.0, .implied_quantity = 3.0, .price_level = 1, .number_of_orders = 2},
      {.price = 2.0, .quantity = 4.0, .implied_quantity = 3.0, .price_level = 1, .number_of_orders = 2},
      {.price = 3.0, .quantity = 8.0, .implied_quantity = 3.0, .price_level = 1, .number_of_orders = 2},
      {.price = 4.0, .quantity = 10.0, .implied_quantity = 3.0, .price_level = 1, .number_of_orders = 2},
      {.price = 5.0, .quantity = 12.0, .implied_quantity = 3.0, .price_level = 1, .number_of_orders = 2},
  };
  roq::MarketByPriceUpdate market_by_price{
      .stream_id = {},
      .exchange = "deribit"sv,
      .symbol = "BTC-27DEC19"sv,
      .bids = {bids, std::size(bids)},
      .asks = {asks, std::size(asks)},
      .update_type = UpdateType::SNAPSHOT,
      .exchange_time_utc = {},
      .exchange_sequence = 123,
      .price_decimals = Decimals::_0,
      .quantity_decimals = Decimals::_1,
      .max_depth = 10,
      .checksum = 123,
  };
  auto result = fmt::format("{}"sv, market_by_price);
  CHECK(std::size(result) > size_t{0});
  // note! Decimals are shown with the '_' prefix due to magic_enum
  auto expected =
      R"({)"
      R"(stream_id=0, )"
      R"(exchange="deribit", )"
      R"(symbol="BTC-27DEC19", )"
      R"(bids=[{price=1, quantity=2, implied_quantity=3, price_level=1, number_of_orders=2}, {price=2, quantity=4, implied_quantity=3, price_level=1, number_of_orders=2}, {price=3, quantity=8, implied_quantity=3, price_level=1, number_of_orders=2}, {price=4, quantity=10, implied_quantity=3, price_level=1, number_of_orders=2}, {price=5, quantity=12, implied_quantity=3, price_level=1, number_of_orders=2}], )"
      R"(asks=[{price=1, quantity=2, implied_quantity=3, price_level=1, number_of_orders=2}, {price=2, quantity=4, implied_quantity=3, price_level=1, number_of_orders=2}, {price=3, quantity=8, implied_quantity=3, price_level=1, number_of_orders=2}, {price=4, quantity=10, implied_quantity=3, price_level=1, number_of_orders=2}, {price=5, quantity=12, implied_quantity=3, price_level=1, number_of_orders=2}], )"
      R"(update_type=SNAPSHOT, )"
      R"(exchange_time_utc=0ns, )"
      R"(exchange_sequence=123, )"
      R"(price_decimals=_0, )"
      R"(quantity_decimals=_1, )"
      R"(max_depth=10, )"
      R"(checksum=123)"
      R"(})"sv;
  CHECK(result == expected);
}
