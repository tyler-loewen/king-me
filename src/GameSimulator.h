#ifndef GAMESIMULATOR_H
#define GAMESIMULATOR_H

#include <memory>
#include <stdexcept>
#include <vector>
#include "Simulator.h"
#include "BoardInterface.h"
#include "PieceInterface.h"
#include "Display.h"
#include "MouseListener.h"
#include "MouseMotionListener.h"
#include "UIntPoint.h"
#include "PieceMove.h"

/**
 * An enum for all possible players (none, player 1, and player 2).
 */
enum PLAYER { NONE, PLAYER1, PLAYER2 };

/**
 * A struct containing data for every cell/tile on the game board.
 */
struct BoardCellData
{
   /**
    * The player who owns the piece which is on the cell.
    */
   PLAYER player;

   /**
    * True if the piece on the cell is a king; false otherwise.
    */
   bool is_king;

   /**
    * Constructs a new board cell data object with no player, and no king piece.
    */
   BoardCellData():player(NONE),is_king(false) {}

   /**
    * Constructs a new board cell data object, with a piece on it owned by the specified player.
    *
    * @param player - The owner of the piece which is on the cell.
    * @param is_king - True if the piece on the cell is a king; false otherwise.
    */
   BoardCellData(PLAYER player, bool is_king):player(player),is_king(is_king) {}
};

class GameSimulator;

/**
 * A class used for listening to mouse clicks.
 */
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
  private:
   /**
    * A reference to the game simulator.
    */
   GameSimulator &game;
};

/**
 * A class for listening to mouse movements.
 */
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
  private:
   /**
    * A reference to the game simulator.
    */
   GameSimulator &game;
};

class GameSimulatorTestFixture;

/**
 * A class for simulating a game of checkers.
 */
class GameSimulator : public Simulator
{
   friend class GameMouseListener;
   friend class GameMouseMotionListener;
   friend class GameSimulatorTestFixture;
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

   /**
    * Sets the piece object for player 1 (so we know how to draw player 1's pieces).
    *
    * Player 1 is the top player.
    */
   void setPlayerOnePiece(std::shared_ptr<PieceInterface> piece);

   /**
    * Sets the piece object for player 2 (so we know how to draw player 2's pieces).
    *
    * Player 2 is the bottom player.
    */
   void setPlayerTwoPiece(std::shared_ptr<PieceInterface> piece);
  private:
   /**
    * A shared pointer to the game board.
    */
   std::shared_ptr<BoardInterface> board;

   /**
    * A shared pointer to the piece object for player 1;
    */
   std::shared_ptr<PieceInterface> player1_piece;

   /**
    * A shared pointer to the piece object for player 2.
    */
   std::shared_ptr<PieceInterface> player2_piece;

   /**
    * The cell data for the board.
    */
   BoardCellData cell_data[8][8];

   /**
    * Stores which cell is highlighted. If no cell is highlighted, the integers are both -1
    */
   int selected_cell[2];

   /**
    * The player whose turn it is.
    */
   PLAYER player_turn;

   /**
    * Initializes the board to a an initial state.
    */
   void init();

   /**
    * Handles cell clicks. Determines if the current player can select a cell, can move to a cell, etc.
    *
    * @param cell_x - The x position of the cell.
    * @param cell_y - The y position of the cell.
    *
    * @throws std::out_of_range - If the cell coordinates are out of bounds.
    */
   void clickCell(unsigned int cell_x, unsigned int cell_y);

   /**
    * Determines if the current player can select a cell. A moveable game piece belonging to the player must be
    * on the cell for the player to be able to select it.
    *
    * @param cell_x - The x position of the cell.
    * @param cell_y - The y position of the cell.
    *
    * @throws std::out_of_range - If the cell coordinates are out of bounds.
    */
   bool canSelectCell(unsigned int cell_x, unsigned int cell_y) const;

   /**
    * Gets the possible moves for the given player.
    *
    * @param player - The player for whom we should get the moves.
    *
    * @return A vector of the possible moves. Empty if the player is trapped.
    */
   std::vector<PieceMove> getPossibleMoves(PLAYER player) const;

   /**
    * Called after a move has been made. Checks for kinging, turn changes, and victory.
    *
    * @param jump_made - True if a jump over an enemy piece was made; false otherwise.
    */
   void postMove(bool jump_made);
};

#endif
