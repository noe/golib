#ifndef GO_BOARD_HEADER_SEEN__
#define GO_BOARD_HEADER_SEEN__

#include <boost/noncopyable.hpp>

namespace go
{

enum class PositionState : uint8_t { BLACK, WHITE, EMPTY };

enum class Player : uint8_t { BLACK, WHITE };

struct Pass {};

struct Position { uint8_t x; uint8_t y; };

typedef Move boost::variant<Pass, Position>;

typedef boost::function<void(*)(const Position&, PositionState)> BoardIterator;

struct Board : boost::noncopyable
{
  static const size_t SIZE = 19;

  Board (unsigned handicap = 0);

  State at (const Vertex& vertex)

  void iterate (BoardIterator it);

  void play (const Move&);

  Player nextMovePlayer ();
};

}
#endif
