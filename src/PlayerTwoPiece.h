#ifndef PLAYERTWOPIECE_H
#define PLAYERTWOPIECE_H

#include "PieceInterface.h"

/**
 * A default implementation of PieceInterface for player two.
 */
class PlayerTwoPiece : public PieceInterface
{
  public:
   /**
    * Draws the game piece at the specified location.
    *
    * @param is_king - True if the piece is a "king piece"; false otherwise.
    * @param x - The position to start drawing the piece along the x-axis.
    * @param y - The position to start drawing the piece along the y-axis.
    * @param width - The width of the board cell (in pixels).
    * @param height - The height of the board cell (in pixels).
    */
   void drawPiece(bool is_king, unsigned int x, unsigned int y, unsigned int width, unsigned int height) const;
};

#endif
