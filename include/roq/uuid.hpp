/* Copyright (c) 2017-2022, Hans Erik Thrane */

#pragma once

#include <fmt/format.h>

#include <algorithm>
#include <array>
#include <compare>
#include <utility>

namespace roq {

class UUID final {
 public:
  using value_type = unsigned char;
  using uuid_t = std::array<value_type, 16>;

  UUID() { std::fill(std::begin(uuid_), std::end(uuid_), 0); }

  /*
  // SO 6893700
  template <typename... T>
  UUID(T &&... args) : uuid_{{std::forward<T>(args)...}} {}
  */

  explicit UUID(uuid_t &&value) : uuid_(std::move(value)) {}
  explicit UUID(const uuid_t &value) : uuid_(value) {}

  UUID(const UUID &) = default;
  UUID(UUID &&) = default;

  UUID &operator=(const UUID &) = default;

  constexpr size_t size() const { return std::size(uuid_); }

  constexpr value_type const *data() const { return std::data(uuid_); }

  constexpr value_type &operator[](std::size_t index) { return uuid_[index]; }
  constexpr const value_type &operator[](std::size_t index) const { return uuid_[index]; }

  constexpr operator const uuid_t &() const { return uuid_; }

  constexpr bool empty() const {
    return std::all_of(std::begin(uuid_), std::end(uuid_), [](auto v) { return v == 0; });
  }

  constexpr auto operator<=>(const UUID &) const = default;

 private:
  uuid_t uuid_;
};

static_assert(sizeof(UUID) == 16);

}  // namespace roq

template <>
struct fmt::formatter<roq::UUID> {
  template <typename Context>
  constexpr auto parse(Context &context) {
    return std::begin(context);
  }
  template <typename Context>
  auto format(const roq::UUID &value, Context &context) {
    using namespace std::literals;
    auto data = std::data(value);
    return fmt::format_to(
        context.out(),
        "{:02x}{:02x}{:02x}{:02x}-"
        "{:02x}{:02x}-"
        "{:02x}{:02x}-"
        "{:02x}{:02x}-"
        "{:02x}{:02x}{:02x}{:02x}{:02x}{:02x}"sv,
        data[0],
        data[1],
        data[2],
        data[3],
        data[4],
        data[5],
        data[6],
        data[7],
        data[8],
        data[9],
        data[10],
        data[11],
        data[12],
        data[13],
        data[14],
        data[15]);
  }
};
