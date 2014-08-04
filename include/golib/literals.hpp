///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Copyright Noe Casas, 2014                                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////
#ifndef GO_USER_DEFINED_LITERALS_HEADER_SEEN__
#define GO_USER_DEFINED_LITERALS_HEADER_SEEN__

#include "golib/types.hpp"

namespace go { namespace detail
{

template <char LETTER>
constexpr uint8_t processLetter()
{
  // TODO
  return 0;
}

template <char... DIGITS>
constexpr uint8_t processDigits()
{
  // TODO
  return 0;
}

template <char LETTER, char... DIGITS>
constexpr go::Position processLiteral ()
{
  static_assert(sizeof...(DIGITS) > 0, "No row present");
  static_assert(sizeof...(DIGITS) < 3, "Too large row");

  return go::Position{processLetter<LETTER>(), processDigits<DIGITS...>()};
}

/** User-defined literal for Go positions */
template <char... STR>
constexpr go::Position operator"" _go()
{
  return go::detail::processLiteral<STR...>();
}

}}

#endif
