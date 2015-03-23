#ifndef MOUSEMOTIONLISTENER_H
#define MOUSEMOTIONLISTENER_H

class MouseMotionListener
{
  public:
   /**
    * Destructs the mouse motion listener.
    */
   virtual ~MouseMotionListener() {}

   /**
    * Called when the mouse is moved.
    *
    * @param x - The position of the movement along the x-axis.
    * @param y - The position of the movement along the y-axis.
    */
   virtual void mouseMoved(int x, int y)=0;
};

#endif
