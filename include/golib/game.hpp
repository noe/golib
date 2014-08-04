///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Copyright Noe Casas, 2014                                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////
#ifndef GO_GAME_HEADER_SEEN__
#define GO_GAME_HEADER_SEEN__

#include "golib/board.hpp"
#include "golib/player.hpp"
#include "golib/score.hpp"

#include <memory>
#include <list>

namespace go
{

struct Game
{
  Game(std::unique_ptr<Board> initial,
       Player& black,
       Player& white);

  const Board& initialBoard() const;

  const Board& getCurrentBoard() const;

  bool isLegalMove (const Position& position) const;

  PlayerColor nextMovePlayer () const;

  bool isFinished();

  std::list<Move> moveHistory() const;

  const Score& getScore();
};

}
#endif
