#include <iostream> //TODO: Not needed
#include "GameSimulator.h"
#include "Display.h"

GameSimulator::GameSimulator(const Display &d, unsigned int fps):Simulator(d, fps),player_turn(PLAYER1)
{
   std::shared_ptr<MouseListener> mouse_listener = std::make_shared<GameMouseListener>(*this);
   std::shared_ptr<MouseMotionListener> mouse_motion_listener = std::make_shared<GameMouseMotionListener>(*this);

   addMouseListener(mouse_listener);
   addMouseMotionListener(mouse_motion_listener);

   this->selected_cell[0] = -1;
   this->selected_cell[1] = -1;

   init();
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

      for (unsigned int x = 0; x < 8; x++)
      {
	 for (unsigned int y = 0; y < 8; y++)
	 {
	    if (this->cell_data[x][y].player == NONE)
	    {
	       //We have nothing to draw.
	       
	       continue;
	    }
	    
	   
	    float cell_x;
	    float cell_y;

	    float cell_width;
	    float cell_height;

	    this->board->getCellDimensions(x, y, cell_x, cell_y, cell_width, cell_height);

	    if (this->cell_data[x][y].player == PLAYER1)
	    {
	       if (this->player1_piece != NULL)
	       {
		  this->player1_piece->drawPiece(this->cell_data[x][y].is_king, (unsigned int) cell_x, (unsigned int) cell_y, (unsigned int) cell_width, (unsigned int) cell_height);
	       }
	    }
	    else if (this->cell_data[x][y].player == PLAYER2)
	    {
	       if (this->player2_piece != NULL)
	       {
		  this->player2_piece->drawPiece(this->cell_data[x][y].is_king, (unsigned int) cell_x, (unsigned int) cell_y, (unsigned int) cell_width, (unsigned int) cell_height);
	       }
	    }
	 }
      }

      if (this->selected_cell[0] >= 0 && this->selected_cell[1] >= 0)
      {
	 //A cell has been selected by the player. We can assume the cell coordinates are within bounds since we do the checks
	 //when we set the variable.

	 this->board->drawCellHighlight(this->selected_cell[0], this->selected_cell[1]);
      }
   }

   al_flip_display();
}

void GameSimulator::setBoard(std::shared_ptr<BoardInterface> board)
{
   this->board = board;
}

void GameSimulator::setPlayerOnePiece(std::shared_ptr<PieceInterface> piece)
{
   this->player1_piece = piece;
}

void GameSimulator::setPlayerTwoPiece(std::shared_ptr<PieceInterface> piece)
{
   this->player2_piece = piece;
}

void GameSimulator::init()
{
   //Init the pieces for the top player
   for (unsigned int x = 0; x < 8; x++)
   {
      for (unsigned int y = 0; y < 3; y++)
      {
	 if (x % 2 != y % 2)
	 {
	    this->cell_data[x][y] = BoardCellData(PLAYER1, false);
	 }
      }
   }

   //Init the pieces for the bottom player
   for (unsigned int x = 0; x < 8; x++)
   {
      for (unsigned int y = 5; y < 8; y++)
      {
	 if (x % 2 != y % 2)
	 {
	    this->cell_data[x][y] = BoardCellData(PLAYER2, false);
	 }
      }
   }
}

void GameSimulator::clickCell(unsigned int cell_x, unsigned int cell_y)
{
   if (cell_x >= 8 || cell_y >= 8)
   {
      throw std::out_of_range("Cell coordinates are out of bounds.");
   }

   if (this->selected_cell[0] >= 0 && this->selected_cell[1] && this->cell_data[cell_x][cell_y].player != this->player_turn)
   {
      //A cell is currently selected. The user is attempting to either move a piece.
      //What must happen:
      // - Check if the player has any moves he/she HAS to make. According to checkers rules, players have
      //   to make all possible jumps. The player cannot choose to not jump a piece if a jump is available.
      // - If there are no jumps available, the player has to move to an empty space. If there are no empty
      //   spaces (i.e. the player is trapped and cannot make any moves), that player must forfeit.
      // - After a jump has been made, we need to check if there are still jumps to be made, and loop until
      //   all possible jumps have been made.

      //Checking is a player is trapped should happen when it changes to that player's turn.
   }
   else
   {
      if (canSelectCell(cell_x, cell_y))
      {
	 this->selected_cell[0] = cell_x;
	 this->selected_cell[1] = cell_y;
      }
   }
}

bool GameSimulator::canSelectCell(unsigned int cell_x, unsigned int cell_y) const
{
   if (cell_x >= 8 || cell_y >= 8)
   {
      throw std::out_of_range("Cell coordinates are out of bounds.");
   }

   BoardCellData cell_dat = this->cell_data[cell_x][cell_y];

   if (cell_dat.player != this->player_turn)
   {
      //The piece at this cell is not owned by the current player (or there is no piece there).
      
      return false;
   }

   //TODO: Check if the piece has a spot to move to.

   return true;
}

bool GameSimulator::getMustMoveCell(unsigned int &cell_x, unsigned int &cell_y) const
{
   //Keep in mind that PLAYER1 is the top player, and therefore must move downwards.
   //PLAYER2 is the bottom player, and therefore must move upwards. But king pieces
   //can move either up or down (diagonally, that is).
   
   for (unsigned int x = 0; x < 8; x++)
   {
      for (unsigned int y = 0; y < 8; y++)
      {
	 if (this->cell_data[x][y].player != this->player_turn)
	 {
	    //This cell isn't occupied by the current player.

	    continue;
	 }

	 //We've found a cell which is occupied by the current player. Let's check if
	 //there are any moves which must be made.
	 
	 //TODO
      }
   }
   
   return false;
}

GameMouseListener::GameMouseListener(GameSimulator &game):game(game)
{

}

void GameMouseListener::mousePressed(int x, int y, unsigned int button)
{
   if (this->game.board != NULL)
   {
      try
      {
	 unsigned int cell_x;
	 unsigned int cell_y;

	 this->game.board->getCell(x, y, cell_x, cell_y);

	 this->game.clickCell(cell_x, cell_y);
      }
      catch (std::out_of_range e)
      {
	 //The board was not clicked. We could deselect the cell here...

	 this->game.selected_cell[0] = this->game.selected_cell[1] = -1;
      }
   }
}

void GameMouseListener::mouseReleased(int x, int y, unsigned int button)
{

}

GameMouseMotionListener::GameMouseMotionListener(GameSimulator &game):game(game)
{
   
}

void GameMouseMotionListener::mouseMoved(int x, int y)
{
   
}
