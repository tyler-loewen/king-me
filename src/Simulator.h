#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <allegro5/allegro.h>
#include "Display.h"

class Simulator
{
  protected:
   /**
    * The frames per second to render at.
    */
   unsigned int fps;

   /**
    * The event queue for allegro.
    */
   ALLEGRO_EVENT_QUEUE *event_queue;

   /**
    * Generates events for the simulation.
    */
   ALLEGRO_TIMER *timer;
  public:
   /**
    * Constructs a new simulator with the specified fps.
    *
    * @param fps - The frames per second to render at.
    */
   Simulator(unsigned int fps);

   /**
    * Deconstructs the simulator.
    */
   ~Simulator();

   /**
    * Simulates everything which needs to be rendered. The function blocks until the window closes.
    */
   void run();

   /**
    * Updates the objects which need to be simulated.
    *
    * @param last_update - The time in seconds since the last update.
    */
   void update(double last_update);

   /**
    * Draws all of the objects which need to be simulated.
    */
   void draw();
};

#endif
