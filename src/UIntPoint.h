#ifndef UINTPOINT_H
#define UINTPOINT_H

struct UIntPoint
{
   unsigned int x;
   unsigned int y;
   
   UIntPoint(unsigned int x=0, unsigned int y=0):x(x),y(y) {}
};

#endif
