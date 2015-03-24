#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "PlayerTwoPiece.h"

void PlayerTwoPiece::drawPiece(bool is_king, unsigned int x, unsigned int y, unsigned int width, unsigned int height) const
{
   al_draw_filled_circle(x, y, width / 2, al_map_rgb(255, 255, 0));
}
