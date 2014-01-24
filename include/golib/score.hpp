#ifndef GO_SCORE_HEADER_SEEN__
#define GO_SCORE_HEADER_SEEN__

#include "golib/gotypes.hpp"

namespace go
{

struct PlayerSummary
{
  std::list<Position> liveStones;
  std::list<Position> deadStones;
  std::list<Position> sekiStones;
};


// To be used as argument for Board::iterate
struct StoneCounter
{
  PlayerSummary white;
  PlayerSummary black;

  void operator (const Position& pos, PositionState state);
};

}
#endif
