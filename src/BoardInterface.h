#ifndef BOARDINTERFACE_H
#define BOARDINTERFACE_H

class BoardInterface
{
  public:
   /**
    * Draws the board.
    */
   virtual void draw() const=0;

   /**
    * Gets the position of the board along the x-axis.
    *
    * @return pixel count
    */
   virtual unsigned int getX() const=0;

   /**
    * Gets the position of the board along the y-axis.
    *
    * @return pixel count
    */
   virtual unsigned int getY() const=0;

   /**
    * Gets the width of the board.
    *
    * @return pixel count
    */
   virtual unsigned int getWidth() const=0;

   /**
    * Gets the height of the board.
    *
    * @return pixel count
    */
   virtual unsigned int getHeight() const=0;

   /**
    * Destructs the board.
    */
   virtual ~BoardInterface() {}
};

#endif
