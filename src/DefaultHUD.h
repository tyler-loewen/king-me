#ifndef DEFAULTHUD_H
#define DEFAULTHUD_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include "HUDInterface.h"

class DefaultHUD : public HUDInterface
{
  public:
   /**
    * Constructor for DefaultHUD.
    */
   DefaultHUD();

   /**
    * Destructor for DefaultHUB.
    */
   ~DefaultHUD();
   
/**
 * Draws the HUD with the information specified.
 *
 * @param display_width - The width of the display.
 * @param display_height - The height of the display.
 * @param status - The game status.
 * @param current_player - The name of the current player.
 * @param pieces_captured - The number of pieces captured by the current player.
 */
   void draw(unsigned int display_width, unsigned int display_height, std::string status, std::string current_player, unsigned int pieces_captured);
  private:
   ALLEGRO_FONT *font;
};

#endif
