#ifndef GO_HASHING_HEADER_SEEN__
#define GO_HASHING_HEADER_SEEN__

#include "golib/types.hpp"
#include "golib/board.hpp"

namespace go
{

class TranspositionTable
{
  public:
 
    static const TranspositionTable& instance();

    uint64_t get(PlayerColor player, const Position& position) const;
 
  private:

    TranspositionTable();

    uint64_t id_[go::Board::SIZE * go::Board::SIZE][2 /* black and white */];
};

}
#endif
