///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Copyright Noe Casas, 2014                                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////
#ifndef GO_PLAYER_HEADER_SEEN__
#define GO_PLAYER_HEADER_SEEN__

struct Board;

namespace go
{

struct Player
{
  virtual void init (PlayerColor color, const Board& initial) = 0;

  virtual Move move (const Board& current) = 0;

  ~Player() { /* do nothing */ }
};

}
#endif
