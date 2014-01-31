#include <cassert>

#include "golib/literals.hpp"
#include "golib/board.hpp"
#include "golib/util.hpp"

namespace  // anonymous namespace for secret stuff
{
  void clearBoard(go::PositionState (&board)[go::Board::SIZE * go::Board::SIZE])
  {
    std::fill_n(board,
                go::Board::SIZE * go::Board::SIZE,
                go::PositionState::EMPTY);
  }
}

namespace go
{

///////////////////////////////////////////////////////////////////////////////
Board::Board (unsigned fixedHandicap)
{
  static const Position D4  = { 3,  3},
                        Q16 = {15, 15},
                        D16 = { 3, 15},
                        Q4  = {15,  3},
                        D10 = { 3,  9},
                        Q10 = {15,  9},
                        K4  = { 9,  3},
                        K16 = { 9, 15},
                        K10 = { 9,  9};

  static std::vector<std::vector<Position>> handicap = {
    {D4, Q16},
    {D4, Q16, D16},
    {D4, Q16, D16, Q4},
    {D4, Q16, D16, Q4, K10},
    {D4, Q16, D16, Q4, D10, Q10},
    {D4, Q16, D16, Q4, D10, Q10, K10},
    {D4, Q16, D16, Q4, D10, Q10, K4, K16},
    {D4, Q16, D16, Q4, D10, Q10, K4, K16, K10}};

  assert(fixedHandicap >= 2);
  assert(fixedHandicap <= 9);

  clearBoard(state_);

  for (const Position& pos : handicap[fixedHandicap - 2])
  {
    state_[go::util::position2index(pos)] = PositionState::BLACK;
  }
}

///////////////////////////////////////////////////////////////////////////////
Board::Board (const std::vector<Position>& freeHandicap)
{
  clearBoard(state_);
  for (const Position& pos : freeHandicap)
  {
    state_[go::util::position2index(pos)] = PositionState::BLACK;
  }
}

///////////////////////////////////////////////////////////////////////////////
PositionState Board::at (const Position& position) const
{
  return state_[go::util::position2index(position)];
}

///////////////////////////////////////////////////////////////////////////////
void Board::iterate (Iterator it) const
{
  for (std::size_t k = 0; k < SIZE*SIZE; ++k)
  {
    it(go::util::index2position(k), state_[k]);
  }
}

///////////////////////////////////////////////////////////////////////////////
void Board::play (PlayerColor player, const Position& position)
{
  //TODO
}

}
