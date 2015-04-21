#ifndef UINTPOINT_H
#define UINTPOINT_H

/**
 * A struct for making points whose data is stored in unsigned integers.
 */
struct UIntPoint
{
   /**
    * The position of the point along the x-axis.
    */
   unsigned int x;

   /**
    * The position of the point along the y-axis.
    */
   unsigned int y;

   /**
    * Constructs a new point.
    *
    * @param x - The position of the point along the x-axis.
    * @param y - The position of the point along the y-axis.
    */
   UIntPoint(unsigned int x=0, unsigned int y=0):x(x),y(y) {}
};

#endif
