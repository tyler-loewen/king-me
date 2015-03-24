#include <iostream> //TODO: Not needed
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

void DefaultBoard::draw() const
{
   al_draw_filled_rectangle(board_pos_x, board_pos_y, board_pos_x + board_width, board_pos_y + board_height, al_map_rgb(255, 0, 0));
}

