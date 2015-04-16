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
    * @param height - Inputs the height. 
    * @param width - Inputs the width.
    */
   void draw(float x, float y, float height, float width);

   

};

#endif
