#include <iostream>
#include <string>
#include <memory>
#include "Display.h"
#include "GameSimulator.h"
#include "DefaultBoard.h"

int main()
{
 
   Display display(std::string("King Me!"), 700, 600);

   GameSimulator simulator(display, 30);

   std::shared_ptr<BoardInterface> board_ptr = std::make_shared<DefaultBoard>(display);

   simulator.setBoard(board_ptr);

   //TODO: Code to set the pieces

   simulator.run();
   
   return 0;
}
