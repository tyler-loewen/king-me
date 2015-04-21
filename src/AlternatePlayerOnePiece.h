#ifndef ALTERNATEPLAYERONEPIECE_H
#define ALTERNATEPLAYERONEPIECE_H

#include "PieceInterface.h"

/**
 * An alternate implementation of PieceInterface for player one.
 */
class AlternatePlayerOnePiece : public PieceInterface
{
  public:
   /**
    ** Alternate constructor for player one pieces.
    */
   AlternatePlayerOnePiece(unsigned char player1_r = 236, unsigned char player1_g = 217,
		  unsigned char player1_b = 141);
   /**
    * Destructs the AlternatePlayerOne Piece
    */
   ~AlternatePlayerOnePiece();
   
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
  
  private:
   /**
    * Amount of red in the player one pieces.
    */
   unsigned char player1_red;

   /**
    * Amount of green in the player one pieces.
    */
   unsigned char player1_green;

   /**
    * Amount of blue in the player one pieces.
    */
   unsigned char player1_blue;

   /**
    * Creates a bitmap to store the crown image
    */
   ALLEGRO_BITMAP *crown;
};

#endif
