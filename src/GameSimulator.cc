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
   //We must draw the board first, then the pieces, then the HUD.
   
   if (this->board != NULL)
   {  
      this->board->draw();
   }
   
   std::cout << "Draw board" << std::endl;
}

void GameSimulator::setBoard(std::shared_ptr<BoardInterface> board)
{
   this->board = board;
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
