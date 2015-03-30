#ifndef PIECEMOVE_H
#define PIECEMOVE_H

#include <vector>
#include "UIntPoint.h"

struct PieceMove
{
   /**
    * The starting position of the piece to be moved.
    */
   UIntPoint start_pos;

   /**
    * The ending position of the piece to be moved.
    */
   UIntPoint end_pos;

   /**
    * A list of pieces we have jumped over for this move (or rather, the piece cell coordinates).
    */
   std::vector<UIntPoint> jumped_pieces;

   PieceMove(UIntPoint start_pos, UIntPoint end_pos):start_pos(start_pos),end_pos(end_pos) {}
};

#endif
