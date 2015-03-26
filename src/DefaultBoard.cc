#include <stdexcept>
#include "DefaultBoard.h"

DefaultBoard::DefaultBoard(const Display &d)
{
   board_width = d.getWidth() - 60;
   board_height = d.getHeight() - 60;
   board_pos_x = 30;
   board_pos_y = 30;
}

unsigned int DefaultBoard::getX() const
{
   return board_pos_x;
}

unsigned int DefaultBoard::getY() const
{
   return board_pos_y;
}

unsigned int DefaultBoard::getWidth() const
{
   return board_width;
}

unsigned int DefaultBoard::getHeight() const
{
   return board_height;
}

void DefaultBoard::getCellDimensions(unsigned int x, unsigned int y, float &cell_x, float &cell_y, float &cell_width, float &cell_height) const
{
   if (x >= 8 || y >= 8)
   {
      throw std::out_of_range("Cell coordinates out-of-bounds.");
   }
   
   cell_width = board_width / 8.0;
   cell_height = board_height / 8.0;
   
   cell_x = board_pos_x + x * cell_width;
   cell_y = board_pos_y + y * cell_height;
}

void DefaultBoard::draw() const
{
   al_draw_rectangle(board_pos_x - 2, board_pos_y - 2, board_pos_x + board_width + 2,
		     board_pos_y + board_height + 2, al_map_rgb(255, 255, 255), 2);

   float cell_width = board_width / 8.0;
   float cell_height = board_height / 8.0;
   
   for (unsigned int x = 0; x < 8; x++)
   {
      for (unsigned int y = 0; y < 8; y++)
      {
	 ALLEGRO_COLOR color;

	 if (x % 2 == y % 2)
	 {
	    color = al_map_rgb(255, 255, 255);
	 }
	 else
	 {
	    color = al_map_rgb(0, 0, 0);
	 }

	 float pos_x = board_pos_x + x * cell_width;
	 float pos_y = board_pos_y + y * cell_height;

	 al_draw_filled_rectangle(pos_x, pos_y, pos_x + cell_width, pos_y + cell_height, color);
	 
      }
   }
}

void DefaultBoard::drawCellHighlight(unsigned int cell_x, unsigned int cell_y) const
{
   float cell_pos_x = 0;
   float cell_pos_y = 0;
   float cell_width = 0;
   float cell_height = 0;

   getCellDimensions(cell_x, cell_y, cell_pos_x, cell_pos_y, cell_width, cell_height);

   al_draw_rectangle(cell_pos_x - 1, cell_pos_y - 1, cell_pos_x + cell_width, cell_pos_y + cell_height, al_map_rgb(110, 110, 110), 3);
}

void DefaultBoard::getCell(int screen_x, int screen_y, unsigned int &cell_x, unsigned int &cell_y) const
{
   if (screen_x < this->board_pos_x || screen_y < this->board_pos_y || screen_x >= this->board_pos_x + this->board_width || screen_y >= this->board_pos_y + this->board_height)
   {
      //(screen_x, screen_y) is not within the bounds of the board.

      throw std::out_of_range("Screen coordinates are not within the bounds of the board.");
   }

   //Make screen coordinates relative to the board.
   screen_x -= this->board_pos_x;
   screen_y -= this->board_pos_y;

   float cell_width = board_width / 8.0;
   float cell_height = board_height / 8.0;

   cell_x = (unsigned int) (screen_x / cell_width);
   cell_y = (unsigned int) (screen_y / cell_height);
}
