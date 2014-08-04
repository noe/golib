///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Copyright Noe Casas, 2014                                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////
#ifndef GO_BOARD_HEADER_SEEN__
#define GO_BOARD_HEADER_SEEN__

#include <boost/noncopyable.hpp>
#include <boost/variant.hpp>
#include <boost/function.hpp>

#include "golib/types.hpp"

namespace go
{

struct Board : boost::noncopyable
{
  static const size_t SIZE = 19;

  typedef boost::function<void (const Position&, PositionState)> Iterator;

  explicit Board (unsigned fixedHandicap);

  explicit Board (const std::vector<Position>& freeHandicap);

  PositionState at (const Position& position) const;

  void iterate (Iterator it) const;

  void play (PlayerColor player, const Position& position);

  uint64_t hash() const;

  private:
  
    PositionState state_[SIZE * SIZE];

    uint64_t hash_;
};

}
#endif
