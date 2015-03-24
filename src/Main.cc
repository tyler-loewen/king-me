#include <iostream>
#include <string>
#include "Display.h"
#include "GameSimulator.h"


int main()
{
 
   Display display(std::string("King Me!"), 700, 600);

   GameSimulator simulator(display, 30);

   //TODO: Code to set the board and pieces

   simulator.run();
   
   return 0;
}
