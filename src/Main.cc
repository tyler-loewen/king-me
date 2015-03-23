#include <iostream>
#include "Display.h"
#include "GameSimulator.h"

int main()
{
   Display display(700, 600);

   GameSimulator simulator(display, 30);

   //TODO: Code to set the board and pieces

   simulator.run();
   
   return 0;
}
