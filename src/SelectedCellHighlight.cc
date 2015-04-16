#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "SelectedCellHighlight.h"

void draw(float x, float y, float height, float width)
{

   al_draw_rectangle(x - 1, y - 1, x + width, y + height, al_map_rgb(110, 110, 110), 3);
   



}
