#ifndef BOARDINTERFACE_H
#define BOARDINTERFACE_H

class BoardInterface
{
  public:
   /**
    * Draws the board.
    */
   virtual void draw()=0;

   /**
    * Gets the position of the board along the x-axis.
    *
    * @return pixel count
    */
   virtual unsigned int getX()=0;

   /**
    * Gets the position of the board along the y-axis.
    *
    * @return pixel count
    */
   virtual unsigned int getY()=0;

   /**
    * Gets the width of the board.
    *
    * @return pixel count
    */
   virtual unsigned int getWidth()=0;

   /**
    * Gets the height of the board.
    *
    * @return pixel count
    */
   virtual unsigned int getHeight()=0;

   /**
    * Destructs the board.
    */
   virtual ~BoardInterface() {}
};

#endif
