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
    ** Default constructor for player two pieces.
    */
  PlayerTwoPiece(unsigned char player2_r = 255, unsigned char player2_g = 255,
		 unsigned char player2_b = 0);
   /**
    * Destructs the PlayerOne Piece
    */
   ~PlayerTwoPiece();
   
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
   * Amount of red in the player two pieces.
   */
  unsigned char player2_red;

  /**
   * Amount of green in the player two pieces.
   */
  unsigned char player2_green;

  /**
   * Amount of blue in the player two pieces.
   */
  unsigned char player2_blue;

   /**
    * Creates a bitmap to store the crown image
    */
   ALLEGRO_BITMAP *crown;
};

#endif
