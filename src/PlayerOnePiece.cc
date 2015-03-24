#include "PlayerOnePiece.h"

void PlayerOnePiece::drawPiece(bool is_king, unsigned int x, unsigned int y, unsigned int width, unsigned int height) const
{
   al_draw_filled_circle(x, y, width / 2, al_map_rgb(0, 0, 255));
}
