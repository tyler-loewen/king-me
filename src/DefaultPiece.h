#ifndef DEFAULTPIECE_H
#define DEFAULTPIECE_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

class DefaultPiece {
  public:
/*
 *This is settting the colour of the piece
 */
   int setColour;

/*
 *This is setting the size of the piece (radius)
 */
   float size;

   /*
    * This is setting a default position for the piece (X coordinate)
    */
   float xPosition;

   /*
    *This is setting a default position for the piece (Y coordinate)
    */
   float yPosition;
   
   DefaultPiece(); 
     private:
};

#endif
