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
    * Gets the dimensions of a specific board cell. The dimensions are stored in the reference parameters.
    *
    * @param x - The x position of the desired cell.
    * @param y - The y position of the desired cell.
    * @param cell_x - A reference to the x position of the cell.
    * @param cell_y - A reference to the y position of the cell.
    * @param cell_width - A reference to the cell width.
    * @param cell_height - A reference to the cell height.
    */
   virtual void getCellDimensions(unsigned int x, unsigned int y, float &cell_x, float &cell_y, float &cell_width, float &cell_height) const=0;

   /**
    * Destructs the board.
    */
   virtual ~BoardInterface() {}
};

#endif
