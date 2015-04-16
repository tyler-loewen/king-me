#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "SelectedCellHighlight.h"

void SelectedCellHighlight::draw(float x, float y, float width, float height)
{
   al_draw_rectangle(x - 1, y - 1, x + width, y + height, al_map_rgb(110, 110, 110), 3);
}
