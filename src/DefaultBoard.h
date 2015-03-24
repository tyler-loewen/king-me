#ifndef DEFAULTBOARD_H
#define DEFAULTBOARD_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "BoardInterface.h"
#include "Display.h"

class DefaultBoard : public BoardInterface
{
  public:
   /**
    * Construsts a default game board.
    *
    * @param d - The display size used to create the board.
    */
   DefaultBoard(const Display &d);

   /**
    * Returns the boards position on the x-axis.
    *
    * @return board_pos_x - The boards top left point on the x-axis.
    */
   unsigned int getX() const;

   /**
    * Returns the boards position on the y-axis.
    *
    * @return board_pos_y - The boards top left point on the y-axis.
    */
   unsigned int getY() const;

   /**
    * Returns the width of the board.
    *
    * @return board_width - The width of the board.
    */
   unsigned int getWidth() const;

   /**
    * Returns the height of the board.
    *
    * @return board_height - The height of the board.
    */
   unsigned int getHeight() const;

   /**
    * Draws the board on the display.
    */
   void draw() const;
  private:
   /**
    * The width of the board.
    */
   int board_width;

   /**
    * The height of the board.
    */
   int board_height;

   /**
    * The boards top left point on the x-axis.
    */
   int board_pos_x;

   /**
    * The boards top left point on the y-axis.
    */
   int board_pos_y;
};

#endif
