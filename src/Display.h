#ifndef DISPLAY_H
#define DISPLAY_H

#include <allegro5/allegro.h>
#include <string>

/**
 * A class for creating a GUI frame.
 */
class Display
{
  private:
   /**
    * Display pointer - Points to the current display.
    */
   ALLEGRO_DISPLAY *display;

   /**
    * Width - The width of the display screen.
    */
   int width;
   
   /**
    * Height - The height of the display screen.
    */
   int height;

   /**
    * Title - The title of the display screen.
    */
   std::string title;
  public:
   /**
    * Display Constructor - Initializes allegro and constructs a screen of the given size.
    *
    * @param title - The title of the display screen.
    * @param width - The width of the display screen.
    * @param height - The height of the display screen.
    */
   Display(const std::string &title, int width=800, int height=600);

   /**
    * Display Destructor - Closes the allegro window.
    */
   ~Display();

   /**
    * Returns the width of the display.
    *
    * @return width - The width of the display.
    */
   int getWidth() const
   {
      return width;
   }

   /**
    * Returns the height of the display.
    *
    * @return height - The height of the display.
    */
   int getHeight() const
   {
      return height;
   }

   /**
    * Returns a pointer to the current dispaly.
    *
    * @return display - A pointer to the current display.
    */
   ALLEGRO_DISPLAY *getAllegroDisplay() const
   {
      return display;
   }
};

#endif
