/* Copyright (c) 2017-2022, Hans Erik Thrane */

#pragma once

#include <utility>

#include "roq/message_info.hpp"

namespace roq {

//! Event
template <typename T>
struct Event final {
  using value_type = T const;

  Event(MessageInfo const &message_info_, value_type const &value_) : message_info(message_info_), value(value_) {}

  Event(Event const &) = delete;

  //! Dispatch to handler
  template <typename Result, typename Handler, typename... Args>
  Result dispatch(Handler &&handler, Args &&...args) const {
    return handler(*this, std::forward<Args>(args)...);
  }

  //! Access MessageInfo
  operator MessageInfo const &() const { return message_info; }

  //! Access Message
  operator value_type const &() const { return value; }

  //! Structured binding
  operator std::pair<MessageInfo const &, value_type const &>() const { return {message_info, value}; }

  MessageInfo const &message_info;  //!< MessageInfo
  value_type const &value;          //!< Message
};

//! Create event and dispatch to handler
template <typename Handler, typename T, typename... Args>
inline void create_event_and_dispatch(
    Handler &&handler, MessageInfo const &message_info, const T &value, Args &&...args) {
  const Event event{message_info, value};
  return event.template dispatch<void>(handler, std::forward<Args>(args)...);
}

}  // namespace roq
