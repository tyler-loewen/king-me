#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "PlayerTwoPiece.h"

PlayerTwoPiece::PlayerTwoPiece(unsigned char player2_r, unsigned char player2_g,
			       unsigned char player2_b)
  : player2_red(player2_r), player2_green(player2_g), player2_blue(player2_b) {}

void PlayerTwoPiece::drawPiece(bool is_king, unsigned int x, unsigned int y, unsigned int width, unsigned int height) const
{
   float cx = x + (width / 2.0);
   float cy = y + (height / 2.0);
   
   al_draw_filled_ellipse(cx, cy, width / 2.5, height / 2.5, al_map_rgb(player2_red,
									player2_green,
									player2_blue));
}
