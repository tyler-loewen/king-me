#ifndef HIGHTLIGHTCELLINTERFACE_H
#define HIGHLIGHTCELLINTERFACE_H

class HighlightCellInterface
{
  public:
   /**
    * Take from the default board interface and highlight the cell.
    * 
    * @param x - Inputs the X value (x-axis).
    * @param y - Inputs the Y value (y-axis).
    * @param height - Inputs the height.
    * @param width - Inputs the width.
    */
   virtual void draw(float x, float y, float height, float width) = 0;
   /**
    * Destructs the the HighlightCellInterface.
    */
   virtual ~HighlightCellInterface() {}
};

#endif
