#ifndef SELECTEDCELLHIGHLIGHT_H
#define SELECTEDCELLHIGHLIGHT_H

#include "HighlightCellInterface.h"

class SelectedCellHighlight : public HighlightCellInterface
{
  public:
   /**
    * Drawing the cell highlight for the cell selected by the use.
    * 
    * @param x - Inputs the X value (x-axis).
    * @param y - Inputs the Y value (y-axis).
    * @param width - Inputs the width.
    * @param height - Inputs the height. 
    */
   void draw(float x, float y, float width, float height);
};

#endif
