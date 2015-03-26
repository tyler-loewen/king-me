#ifndef MOUSELISTENER_H
#define MOUSELISTENER_H

/**
 * An interface for a mouse listener (listens for mouse clicks).
 */
class MouseListener
{
  public:
   /**
    * Destructs the mouse listener.
    */
   virtual ~MouseListener() {}

   /**
    * Called when a mouse button is pressed.
    *
    * @param x - The mouse position along the x-axis when the mouse was pressed.
    * @param y - The mouse position along the y-axis when the mouse was pressed.
    * @param button - The button which was pressed.
    */
   virtual void mousePressed(int x, int y, unsigned int button)=0;

   /**
    * Called when a mouse button is released.
    *
    * @param x - The mouse position along the x-axis when the mouse was released.
    * @param y - The mouse position along the y-axis when the mouse was released.
    * @param button - The button which was released.
    */
   virtual void mouseReleased(int x, int y, unsigned int button)=0;
};

#endif
