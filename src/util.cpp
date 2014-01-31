#include "golib/util.hpp"

namespace go { namespace util
{
 
go::Position index2position(std::size_t index)
{
  go::Position pos;
  pos.horizontal = index / go::Board::SIZE;
  pos.vertical   = index % go::Board::SIZE;

  assert(pos.horizontal < go::Board::SIZE);
  return std::move(pos);
}

std::size_t position2index(const go::Position& pos)
{
  return pos.horizontal * go::Board::SIZE + pos.vertical;
}

}}
