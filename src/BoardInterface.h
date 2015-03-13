#ifndef BOARDINTERFACE_H
#define BOARDINTERFACE_H

class BoardInterface
{
  public:
   /**
    * Draws the game board at the specified location.
    *
    * @param x - The position to start drawing the board along the x-axis.
    * @param y - The position to start drawing the board along the y-axis.
    * @param width - The width of the board (in pixels).
    * @param height - The height of the board (in pixels).
    */
   virtual void drawBoard(unsigned int x, unsigned int y, unsigned int width, unsigned int height)=0;
};

#endif
