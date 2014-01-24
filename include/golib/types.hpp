#ifndef GO_TYPES_HEADER_SEEN__
#define GO_TYPES_HEADER_SEEN__

#include <boost/variant.hpp>

namespace go
{

/******************************************************************************
 * A position within the Go board. On a 19x19 board indexes go from 0 to 18.
 * Horizontal indexes grow from the left to the right.
 * Vertical indexes grow from the bottom to the top.
 * This way:
 *   - the lower left corner is called {0,0},
 *   - the lower right corner {18,0},
 *   - the upper left corner {0, 18},
 *   - the upper right corner {18, 18}.
 ****************************************************************************/
struct Position { uint8_t horizontal; uint8_t vertical; };

/** Dummy structure to mark a pass movement. */
struct Pass {};

/** A move by a player */
typedef boost::variant<Pass, Position> Move;

/** Players' colors */
enum class PlayerColor : uint8_t { BLACK, WHITE };

/** Possible states for certain position within the board */
enum class PositionState : uint8_t { BLACK, WHITE, EMPTY };


}

#endif
