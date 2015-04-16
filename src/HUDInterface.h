#ifndef HUDINTERFACE_H
#define HUDINTERFACE_H

#include <string>

class HUDInterface
{
  public:
   /**
    * Virtual destructor for the HUD.
    */
   virtual ~HUDInterface() {}

   /**
    * Draws the HUD with the information specified.
    *
    * @param display_width - The width of the display.
    * @param display_height - The height of the display.
    * @param status - The game status.
    * @param current_player - The name of the current player.
    * @param pieces_captured - The number of pieces captured by the current player.
    */
   virtual void draw(unsigned int display_width, unsigned int display_height, std::string status, std::string current_player, unsigned int pieces_captured)=0;
};

#endif
