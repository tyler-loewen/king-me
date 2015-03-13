#include <allegro5/allegro_primitives.h>
#include <iostream>
#include <cstdlib>
#include "Display.h"


Display::Display(int w, int h)
{
   width = w;
   height = h;

   al_init();
   
  
   //If the display cannot be initialized, we exit.
   
   if((display = al_create_display(width, height)) == NULL)
   {
      std::cerr << "Cannot intialize the display" << std::endl;
      
      exit(1);
   }

   al_init_primitives_addon();
}

Display::~Display()
{
   al_destroy_display(display);
}
