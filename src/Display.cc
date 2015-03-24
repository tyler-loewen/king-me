#include <allegro5/allegro_primitives.h>
#include <iostream>
#include <cstdlib>
#include "Display.h"


Display::Display(const std::string &t, int w, int h)
{
   width = w;
   height = h;
   title = t;
   al_init();
  
   //If the display cannot be initialized, we exit.
   
   if((display = al_create_display(width, height)) == NULL)
   {
      std::cerr << "Cannot intialize the display" << std::endl;
      
      exit(1);
   }
   
   al_set_window_title(this->display, title.c_str());
   al_init_primitives_addon();
}

Display::~Display()
{
   al_destroy_display(display);
}
