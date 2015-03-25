#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdexcept>
#include <iostream> //TODO Not needed

#include "Simulator.h"
#include "Display.h"

Simulator::Simulator(const Display &d, unsigned int fps):fps(fps),active(false),mouse_in_display(true)
{
   if ((this->timer = al_create_timer(1.0 / fps)) == NULL)
   {
      throw new std::runtime_error("Cannot create allegro timer.");
   }

   if ((this->event_queue = al_create_event_queue()) == NULL)
   {
      throw new std::runtime_error("Cannot create event queue.");
   }

   //Installs a mouse driver so we can listen for mouse events
   al_install_mouse();

   al_register_event_source(this->event_queue, al_get_display_event_source(d.getAllegroDisplay()));
   al_register_event_source(this->event_queue, al_get_timer_event_source(this->timer));
   al_register_event_source(this->event_queue, al_get_mouse_event_source());

   al_start_timer(this->timer);

   this->active = true;
}

Simulator::~Simulator()
{
   if (this->timer != NULL)
   {
      al_destroy_timer(this->timer);

      this->timer = NULL;
   }

   if (this->event_queue != NULL)
   {
      al_destroy_event_queue(this->event_queue);

      this->event_queue = NULL;
   }

   this->mouse_listeners.clear();
   this->mouse_motion_listeners.clear();
}

void Simulator::addMouseListener(std::shared_ptr<MouseListener> listener_ptr)
{
   this->mouse_listeners.push_back(listener_ptr);
}

void Simulator::addMouseMotionListener(std::shared_ptr<MouseMotionListener> listener_ptr)
{
   this->mouse_motion_listeners.push_back(listener_ptr);
}

void Simulator::sendToMouseListeners(const ALLEGRO_MOUSE_EVENT &e, bool pressed) const
{
   if (!this->mouse_in_display) //TODO: We may not capture release events if the user drags the mouse off screen. Fix this.
   {
      //The mouse isn't in the display. Don't send the event to the listeners.
      
      return;
   }
   
   for (unsigned int i = 0; i < this->mouse_listeners.size(); i++)
   {
      if (pressed)
      {
	 this->mouse_listeners[i]->mousePressed(e.x, e.y, e.button);
      }
      else
      {
	 this->mouse_listeners[i]->mouseReleased(e.x, e.y, e.button);
      }
   }
}

void Simulator::sendToMouseMotionListeners(const ALLEGRO_MOUSE_EVENT &e) const
{
   if (!this->mouse_in_display)
   {
      //The mouse isn't in the display. Don't send the event to the listeners.

      return;
   }
   
   if (e.dx == 0 && e.dy == 0)
   {
      //Mouse position didn't change.
      
      return;
   }
   
   for (unsigned int i = 0; i < this->mouse_motion_listeners.size(); i++)
   {
      this->mouse_motion_listeners[i]->mouseMoved(e.x, e.y);
   }
}

void Simulator::run()
{
   bool redraw = true;

   double current_time, previous_time = 0;

   while (this->active)
   {
      ALLEGRO_EVENT event;

      al_wait_for_event(this->event_queue, &event);

      switch (event.type)
      {
	 case ALLEGRO_EVENT_TIMER:
	    current_time = al_current_time();

	    update(current_time - previous_time);

	    redraw = true;

	    break;
	 case ALLEGRO_EVENT_DISPLAY_CLOSE:
	    this->active = false;

	    break;
	 case ALLEGRO_EVENT_MOUSE_AXES:
	    //Either the mouse moved, or the wheel was scrolled.
	    sendToMouseMotionListeners(event.mouse);
	    
	    break;
	 case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
	    //A mouse button was pressed.
	    sendToMouseListeners(event.mouse, true);
	    
	    break;
	 case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
	    //A mouse button was released.
	    sendToMouseListeners(event.mouse, false);

	    break;
	 case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT:
	    //The window is no longer active
	    this->mouse_in_display = false;

	    break;
	 case ALLEGRO_EVENT_DISPLAY_SWITCH_IN:
	    //The window is active once again

	    break;
	 case ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY:
	    //The mouse has entered the allegro display.
	    this->mouse_in_display = true;
	    
	    break;
	 case ALLEGRO_EVENT_MOUSE_LEAVE_DISPLAY:
	    //The mouse has left the allegro display.
	    this->mouse_in_display = false;
	    
	    break;
	 default:
	    std::cout << "Unhandled event." << std::endl;

	    break;
      }

      if (!this->active)
      {
	 break;
      }

      if (redraw && al_is_event_queue_empty(this->event_queue))
      {
	 draw();

	 redraw = false;
      }
   }
}
