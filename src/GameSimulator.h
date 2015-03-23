#ifndef GAMESIMULATOR_H
#define GAMESIMULATOR_H

#include <memory>
#include "Simulator.h"
#include "BoardInterface.h"
#include "Display.h"

class GameSimulator : public Simulator
{
  public:
   /**
    * Constructs a new game simulator with the specified fps.
    *
    * @param d - A reference to the display object.
    * @param fps - The frames per second to render at.
    */
   GameSimulator(const Display &d, unsigned int fps);

   /**
    * Destructs the game simulator.
    */
   ~GameSimulator();

   /**
    * Draws all of the objects which need to be simulated.
    *
    * @param last_update - The time in seconds since the last update.
    */
   void update(double last_update);

   /**
    * Draws all of the objects which need to be simulated.
    */
   void draw() const;
  private:
   /**
    * A shared pointer to the game board.
    */
   std::shared_ptr<BoardInterface> board;
};

#endif
