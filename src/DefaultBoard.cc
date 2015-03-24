#include "DefaultBoard.h"

DefaultBoard::DefaultBoard(const Display &d)
{
   board_width = d.width - 60;
   board_height = d.height - 60;
   board_pos_x = d.width - 30;
   board_pos_y = d.width - 30;
}

unsigned int DefaultBoard::getX()
{
   return board_pos_x;
}

unsigned int DefaultBoard::getY()
{
   return board_pos_y;
}

unsigned int DefaultBoard::getWidth()
{
   return board_width;
}

unsigned int DefaultBoard::getHeight()
{
   return board_height;
}

void DefaultBoard::draw()
{
   al_draw_filled_rectangle(board_pos_x,
			    board_pos_y,
			    board_pos_x + board_width,
			    board_pos_y + board_height,
			    al_map_rgb(250,240,300);
}

