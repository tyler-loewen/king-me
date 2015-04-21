#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "AlternateCellHighlight.h"

void AlternateCellHighlight::draw(float x, float y, float width, float height)
{
   al_draw_rectangle(x - 1, y - 1, x + width, y + height, al_map_rgb(255, 255, 255), 3);
}
