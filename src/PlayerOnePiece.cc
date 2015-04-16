#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include "PlayerOnePiece.h"

PlayerOnePiece::PlayerOnePiece(unsigned char player1_r, unsigned char player1_g,
			       unsigned char player1_b)
   : player1_red(player1_r), player1_green(player1_g), player1_blue(player1_b)
{
   //Assigns the crown image
   crown = al_load_bitmap("img/CrownIcon.png");
}

void PlayerOnePiece::drawPiece(bool is_king, unsigned int x, unsigned int y, unsigned int width, unsigned int height) const
{
   float cx = x + (width / 2.0);
   float cy = y + (height / 2.0);
   
   al_draw_filled_ellipse(cx, cy, width / 2.5, height / 2.5, al_map_rgb(player1_red,
									player1_green,
									player1_blue));
   if (is_king)
   {
      al_draw_scaled_bitmap(crown,
			    0, 0,
			    al_get_bitmap_width(crown),
			    al_get_bitmap_height(crown),
			    x + (width / 4), y + (height / 4),
			    width / 2, height / 2,
			    0);
   }
  
}

PlayerOnePiece::~PlayerOnePiece()
{
   al_destroy_bitmap(crown);
}
