#include <iostream> //TODO: Not needed
#include "GameSimulator.h"
#include "Display.h"

GameSimulator::GameSimulator(const Display &d, unsigned int fps):Simulator(d, fps)
{
   std::shared_ptr<MouseListener> mouse_listener = std::make_shared<GameMouseListener>(*this);
   std::shared_ptr<MouseMotionListener> mouse_motion_listener = std::make_shared<GameMouseMotionListener>(*this);

   addMouseListener(mouse_listener);
   addMouseMotionListener(mouse_motion_listener);
}

GameSimulator::~GameSimulator()
{

}

void GameSimulator::update(double last_update)
{
   
}

void GameSimulator::draw() const
{
   al_clear_to_color(al_map_rgb(0, 0, 0));
   
   //We must draw the board first, then the pieces, then the HUD.
   
   if (this->board != NULL)
   {
      this->board->draw();
   }

   al_flip_display();
}

void GameSimulator::setBoard(std::shared_ptr<BoardInterface> board)
{
   this->board = board;
}

void GameSimulator::init()
{
   //Init the pieces for the top player
   for (unsigned int x = 0; x < 3; x++)
   {
      for (unsigned int y = 0; y < 3; y++)
      {

      }
   }

   //Init the pieces for the bottom player
   for (unsigned int x = 5; x < 8; x++)
   {
      for (unsigned int y = 5; y < 8; y++)
      {
	 
      }
   }

   //Blah. Do the above later. Let's just add a single piece to test.

   this->cell_data[0][0] = BoardCellData(PLAYER1, false);
}

GameMouseListener::GameMouseListener(GameSimulator &game)
{
   
}

void GameMouseListener::mousePressed(int x, int y, unsigned int button)
{

}

void GameMouseListener::mouseReleased(int x, int y, unsigned int button)
{

}

GameMouseMotionListener::GameMouseMotionListener(GameSimulator &game)
{
   
}

void GameMouseMotionListener::mouseMoved(int x, int y)
{
   std::cout << "Mouse moved to (" << x << ", " << y << ")." << std::endl;
}
