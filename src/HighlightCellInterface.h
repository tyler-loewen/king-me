#ifndef HIGHLIGHTCELLINTERFACE_H
#define HIGHLIGHTCELLINTERFACE_H

class HighlightCellInterface
{
  public:
   /**
    * Take from the default board interface and highlight the cell.
    * 
    * @param x - Inputs the X value (x-axis).
    * @param y - Inputs the Y value (y-axis).
    * @param width - Inputs the width.
    * @param height - Inputs the height.
    */
   virtual void draw(float x, float y, float width, float height) = 0;
   /**
    * Destructs the the HighlightCellInterface.
    */
   virtual ~HighlightCellInterface() {}
};

#endif
