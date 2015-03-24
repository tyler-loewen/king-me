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
      throw new std::out_of_range("Cell coordinates out-of-bounds.");
   }
   
   cell_width = board_width / 8.0;
   cell_height = board_height / 8.0;
   
   cell_x = board_pos_x + x * cell_width;
   cell_y = board_pos_y + y * cell_height;
}

void DefaultBoard::draw() const
{
   al_draw_rectangle(board_pos_x - 2, board_pos_y - 2, board_pos_x + board_width + 3,
		     board_pos_y + board_height + 3, al_map_rgb(255, 255, 255), 2);

   float cell_width = board_width / 8.0;
   float cell_height = board_height / 8.0;
   
   for (unsigned int x = 0; x < 8; x++)
   {
      for (unsigned int y = 0; y < 8; y++)
      {
	 ALLEGRO_COLOR color;
	 
	 if (y % 2 == 0)
	 {
	    if (x % 2 == 0)
	    {
	       //Set to white
	       color = al_map_rgb(255, 255, 255);
	    }
	    else
	    {
	       //Set to black
	        color = al_map_rgb(0, 0, 0);
	    }
	 }
	 else
	 {
	    if (x % 2 == 0)
	    {
	       //Set to black
	        color = al_map_rgb(0, 0, 0);
	    }
	    else
	    {
	       //Set to white
	        color = al_map_rgb(255, 255, 255);
	    }
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

   al_draw_rectangle(cell_pos_x - 1, cell_pos_y - 1, cell_pos_x + cell_width + 2, cell_pos_y + cell_height + 2, al_map_rgb(100, 100, 100), 2);
}

void DefaultBoard::getCell(int screen_x, int screen_y, unsigned int &cell_x, unsigned int &cell_y) const
{
   //TODO: Implement
}
