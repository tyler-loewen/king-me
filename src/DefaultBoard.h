#ifndef DEFAULTBOARD_H
#define DEFAULTBOARD_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "BoardInterface.h"
#include "Display.h"

/**
 * A default board for checkers.
 */
class DefaultBoard : public BoardInterface
{
  public:
   /**
    * Construsts a default game board.
    *
    * @param d - The display size used to create the board.
    */
   DefaultBoard(const Display &d, unsigned char tile1_r = 255, unsigned char tile1_g = 255,
		unsigned char tile1_b = 255, unsigned char tile2_r = 0,
		unsigned char tile2_g = 0, unsigned char tile2_b = 0);

   /**
    * Draws the board on the display.
    */
   void draw() const;

   /**
    * Draws the highlight for a cell with the given cell coordinates.
    *
    * @param cell_x - The cell coordinate along the x-axis.
    * @param cell_y - The cell coordinate along the y-axis.
    *
    * @throws std::out_of_range - If the cell coordinates are out of bounds.
    */
   void drawCellHighlight(unsigned int cell_x, unsigned int cell_y) const;

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
    *
    * @throws std::out_of_range - If the cell coordinates are out of bounds.
    */
   void getCellDimensions(unsigned int x, unsigned int y, float &cell_x, float &cell_y, float &cell_width, float &cell_height) const;

   /**
    * Gets the cell coordinates at a given screen coordinate. The cell coordinates are stored in the reference parameters.
    *
    * @param screen_x - The screen position along the x-axis.
    * @param screen_y - The screen position along the y axis.
    * @param cell_x - Reference to the cell coordinate along the x-axis.
    * @param cell_y - Reference to the cell coordinate along the y-axis.
    *
    * @throws std::out_of_range - If the screen coordinates are not within the bounds of the board.
    */
   void getCell(int screen_x, int screen_y, unsigned int &cell_x, unsigned int &cell_y) const;
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

   /**
    * The amount of red colour of the first board tile.
    */
   unsigned char tile1_red;
   
   /**
    * The amount of blue colour of the first board tile.
    */
   unsigned char tile1_blue;
    
   /**
    * The amount of green colour of the first board tile.
    */
   unsigned char tile1_green;
    
   /**
    * The amount of red colour of the second board tile.
    */
   unsigned char tile2_red;
    
   /**
    * The amount of blue colour of the second board tile.
    */
   unsigned char tile2_blue;
    
   /**
    * The amount of green colour of the second board tile.
    */
   unsigned char tile2_green;  
};

#endif
