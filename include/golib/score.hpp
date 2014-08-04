///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Copyright Noe Casas, 2014                                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////
#ifndef GO_SCORE_HEADER_SEEN__
#define GO_SCORE_HEADER_SEEN__

#include "golib/types.hpp"
#include <list>

namespace go
{

struct PlayerSummary
{
  std::list<Position> liveStones;
  std::list<Position> deadStones;
  std::list<Position> sekiStones;
};

struct Score
{
  PlayerSummary white;
  PlayerSummary black;
};

// To be used as argument for Board::iterate
struct StoneCounter
{
  Score score;
  void operator() (const Position& pos, PositionState state);
};

}
#endif
