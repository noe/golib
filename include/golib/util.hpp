#ifndef GO_UTIL_HEADER_SEEN__
#define GO_UTIL_HEADER_SEEN__

#include "golib/types.hpp"
#include "golib/board.hpp"

namespace go { namespace util
{

go::Position index2position(std::size_t index);

std::size_t position2index(const go::Position& pos);

}}
#endif
