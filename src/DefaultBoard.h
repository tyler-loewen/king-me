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
    * Gets the dimensions of a specific board cell. The dimensions are stored in the reference parameters.
    *
    * @param x - The x position of the desired cell.
    * @param y - The y position of the desired cell.
    * @param cell_x - A reference to the x position of the cell.
    * @param cell_y - A reference to the y position of the cell.
    * @param cell_width - A reference to the cell width.
    * @param cell_height - A reference to the cell height.
    */
    void getCellDimensions(unsigned int x, unsigned int y, float &cell_x, float &cell_y, float &cell_width, float &cell_height) const;
   
   /**
    * Draws the board on the display.
    */
   void draw() const;  
  private:
   /**
    * The width of the board.
    */
   unsigned int board_width;

   /**
    * The height of the board.
    */
   unsigned int board_height;

   /**
    * The boards top left point on the x-axis.
    */
   unsigned int board_pos_x;

   /**
    * The boards top left point on the y-axis.
    */
   unsigned int board_pos_y;
};

#endif
