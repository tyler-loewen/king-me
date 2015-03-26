#ifndef PIECEINTERFACE_H
#define PIECEINTERFACE_H

/**
 * An interface used for drawing pieces.
 */
class PieceInterface
{
  public:
   /**
    * Draws the game piece at the specified location.
    *
    * @param is_king - True if the piece is a "king piece"; false otherwise.
    * @param x - The position to start drawing the piece along the x-axis.
    * @param y - The position to start drawing the piece along the y-axis.
    * @param width - The width of the board (in pixels).
    * @param height - The height of the board (in pixels).
    */
   virtual void drawPiece(bool is_king, unsigned int x, unsigned int y, unsigned int width, unsigned int height) const=0;

   /**
    * Destructs the piece.
    */
   virtual ~PieceInterface() {}
};

#endif
