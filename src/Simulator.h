#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <memory>
#include <vector>
#include <allegro5/allegro.h>
#include "Display.h"
#include "MouseListener.h"
#include "MouseMotionListener.h"

class Simulator
{
  private:
   /**
    * The state of the simulator. True if active; false otherwise.
    */
   bool active;

   /**
    * A list of smart pointers to mouse listeners.
    */
   std::vector<std::shared_ptr<MouseListener>> mouse_listeners;

   /**
    * A list of smart pointers to mouse motion listeners.
    */
   std::vector<std::shared_ptr<MouseMotionListener>> mouse_motion_listeners;

   /**
    * Sends a mouse click/release event to the listeners.
    *
    * @param e - The mouse event.
    * @param pressed - True if the mouse was pressed; false if released.
    */
   void sendToMouseListeners(const ALLEGRO_MOUSE_EVENT &e, bool pressed) const;

   /**
    * Sets a mouse movement event to the listeners.
    *
    * @param e - The mouse movement event.
    */
   void sendToMouseMotionListeners(const ALLEGRO_MOUSE_EVENT &e) const;
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
    * @param d - A reference to the display object.
    * @param fps - The frames per second to render at.
    */
   Simulator(const Display &d, unsigned int fps);

   /**
    * Destructs the simulator.
    */
   ~Simulator();

   /**
    * Adds a mouse listener, which listens for mouse events on the allegro display.
    *
    * @param listener_ptr A smart pointer to the listener.
    */
   void addMouseListener(std::shared_ptr<MouseListener> listener_ptr);

   /**
    * Adds a mouse motion listener, which listens for mouse motion events on the allegro display.
    *
    * @param listener_ptr A smart pointer to the listener.
    */
   void addMouseMotionListener(std::shared_ptr<MouseMotionListener> listener_ptr);

   /**
    * Simulates everything which needs to be rendered. The function blocks until the window closes.
    */
   void run();

   /**
    * Updates the objects which need to be simulated.
    *
    * @param last_update - The time in seconds since the last update.
    */
   virtual void update(double last_update)=0;

   /**
    * Draws all of the objects which need to be simulated.
    */
   virtual void draw() const=0;
};

#endif
