#ifndef GAMESIMULATOR_H
#define GAMESIMULATOR_H

#include <memory>
#include "Simulator.h"
#include "BoardInterface.h"
#include "Display.h"
#include "MouseListener.h"
#include "MouseMotionListener.h"

class GameSimulator;

class GameMouseListener : public MouseListener
{
  public:
   /**
    * Constructs a new mouse listener for the game.
    *
    * @param game - Reference to the game simulator.
    */
   GameMouseListener(GameSimulator &game);

   /**
    * Called when a mouse button is pressed.
    *
    * @param x - The mouse position along the x-axis when the mouse was pressed.
    * @param y - The mouse position along the y-axis when the mouse was pressed.
    * @param button - The button which was pressed.
    */
   void mousePressed(int x, int y, unsigned int button);

   /**
    * Called when a mouse button is released.
    *
    * @param x - The mouse position along the x-axis when the mouse was released.
    * @param y - The mouse position along the y-axis when the mouse was released.
    * @param button - The button which was released.
    */
   void mouseReleased(int x, int y, unsigned int button);
};

class GameMouseMotionListener : public MouseMotionListener
{
  public:
   /**
    * Constructs a new mouse motion listener for the game.
    *
    * @param game - Reference to the game simulator.
    */
   GameMouseMotionListener(GameSimulator &game);

   /**
    * Called when the mouse is moved.
    *
    * @param x - The position of the movement along the x-axis.
    * @param y - The position of the movement along the y-axis.
    */
   void mouseMoved(int x, int y);
};

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

   /**
    * Sets the board object for the game.
    *
    * @param board - A shared pointer to the board object.
    */
   void setBoard(std::shared_ptr<BoardInterface> board);
  private:
   /**
    * A shared pointer to the game board.
    */
   std::shared_ptr<BoardInterface> board;
};

#endif
