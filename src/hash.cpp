///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Copyright Noe Casas, 2014                                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "golib/hash.hpp"
#include "golib/util.hpp"

namespace go
{

///////////////////////////////////////////////////////////////////////////////
const TranspositionTable& TranspositionTable::instance()
{
  static TranspositionTable instance;
  return instance;
}

///////////////////////////////////////////////////////////////////////////////
uint64_t TranspositionTable::get(PlayerColor player, const Position& position) const
{
  return id_[go::util::position2index(position)][static_cast<size_t>(player)];
}
 
///////////////////////////////////////////////////////////////////////////////
TranspositionTable::TranspositionTable()
{
  //TODO: initialize
}

}
