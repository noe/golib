#ifndef GO_GAME_HEADER_SEEN__
#define GO_GAME_HEADER_SEEN__

#include "golib/board.hpp"
#include "golib/player.hpp"

namespace go
{

struct Game
{
  const Game(std::unique_ptr<Board> initialm,
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
