#include <iostream> //TODO: Not needed
#include "GameSimulator.h"
#include "Display.h"

GameSimulator::GameSimulator(const Display &d, unsigned int fps):Simulator(d, fps),d(d),player_turn(PLAYER1),status("Please make a move."),player1_pieces_captured(0),player2_pieces_captured(0)
{
   std::shared_ptr<MouseListener> mouse_listener = std::make_shared<GameMouseListener>(*this);
   std::shared_ptr<MouseMotionListener> mouse_motion_listener = std::make_shared<GameMouseMotionListener>(*this);

   addMouseListener(mouse_listener);
   addMouseMotionListener(mouse_motion_listener);

   this->selected_cell[0] = this->selected_cell[1] = -1;
   this->must_move_cell[0] = this->must_move_cell[1] = -1;

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

      if (this->selected_cell[0] >= 0 && this->selected_cell[1] >= 0 && this->selected_cell_highlight != NULL)
      {
	 //A cell has been selected by the player. We can assume the cell coordinates are within bounds since we do the checks
	 //when we set the variable.

	 //this->board->drawCellHighlight(this->selected_cell[0], this->selected_cell[1]);

	 float cell_pos_x = 0;
	 float cell_pos_y = 0;
	 float cell_width = 0;
	 float cell_height = 0;

	 this->board->getCellDimensions(this->selected_cell[0], this->selected_cell[1], cell_pos_x, cell_pos_y, cell_width, cell_height);

	 this->selected_cell_highlight->draw(cell_pos_x, cell_pos_y, cell_width, cell_height);
      }

      if (this->hud != NULL)
      {
	 std::string player_name;

	 if (this->player_turn == PLAYER1)
	 {
	    player_name += "Player 1 (Top)";
	 }
	 else if (this->player_turn == PLAYER2)
	 {
	    player_name += "Player 2 (Bottom)";
	 }
	 else
	 {
	    player_name = "None";
	 }
	 
	 this->hud->draw(this->d.getWidth(), this->d.getHeight(), this->status, player_name, this->player_turn == PLAYER1 ? this->player1_pieces_captured : this->player_turn == PLAYER2 ? this->player2_pieces_captured : 0);
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

void GameSimulator::setHUD(std::shared_ptr<HUDInterface> hud)
{
   this->hud = hud;
}

void GameSimulator::setSelectedCellHighlight(std::shared_ptr<HighlightCellInterface> highlight)
{
   this->selected_cell_highlight = highlight;
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

   if (this->selected_cell[0] >= 0 && this->selected_cell[1] >= 0 && this->cell_data[cell_x][cell_y].player != this->player_turn)
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

      std::vector<PieceMove> possible_moves = getPossibleMoves(this->player_turn);

      //Let's check if we can move to the clicked cell.

      //If the current player must jump an opponent piece
      bool must_jump = false;

      for (unsigned int i = 0; i < possible_moves.size(); i++)
      {
	 if (possible_moves[i].jumped_pieces.size() > 0)
	 {
	    must_jump = true;

	    break;
	 }
      }

      for (unsigned int i = 0; i < possible_moves.size(); i++)
      {
	 PieceMove move = possible_moves[i];
	 
	 if (this->selected_cell[0] == move.start_pos.x && this->selected_cell[1] == move.start_pos.y && move.end_pos.x == cell_x && move.end_pos.y == cell_y)
	 {
	    //We have found a move for the clicked cell.

	    if (!must_jump || possible_moves[i].jumped_pieces.size() > 0)
	    {
	       //Let's make the jump.

	       //Remove the jumped pieces.
	       for (unsigned int j = 0; j < move.jumped_pieces.size(); j++)
	       {
		  UIntPoint jumped_cell = move.jumped_pieces[j];

		  this->cell_data[jumped_cell.x][jumped_cell.y] = BoardCellData();
	       }

	       BoardCellData data = this->cell_data[move.start_pos.x][move.start_pos.y];

	       //Make the move.
	       this->cell_data[move.start_pos.x][move.start_pos.y] = BoardCellData();
	       this->cell_data[cell_x][cell_y] = data;

	       this->selected_cell[0] = cell_x;
	       this->selected_cell[1] = cell_y;

	       postMove(must_jump);
	    }

	    break;
	 }
      }
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

bool GameSimulator::canSelectCell(unsigned int cell_x, unsigned int cell_y)
{
   if (cell_x >= 8 || cell_y >= 8)
   {
      throw std::out_of_range("Cell coordinates are out of bounds.");
   }

   if (this->must_move_cell[0] >= 0 && this->must_move_cell[1] >= 0)
   {
      status = "There is a move that must be made.";
      
      return this->must_move_cell[0] == cell_x && this->must_move_cell[1] == cell_y;
   }

   BoardCellData cell_dat = this->cell_data[cell_x][cell_y];

   if (cell_dat.player != this->player_turn)
   {
      //The piece at this cell is not owned by the current player (or there is no piece there).

      this->status = "This isn't our piece.";
      
      return false;
   }

   std::vector<PieceMove> possible_moves = getPossibleMoves(cell_dat.player);

   //If the current player must jump an opponent piece
   bool must_jump = false;

   for (unsigned int i = 0; i < possible_moves.size(); i++)
   {
      if (possible_moves[i].jumped_pieces.size() > 0)
      {
	 must_jump = true;

	 break;
      }
   }

   //Find the piece associated with the cell (cell_x, cell_y).
   for (unsigned int i = 0; i < possible_moves.size(); i++)
   {
      if (possible_moves[i].start_pos.x == cell_x && possible_moves[i].start_pos.y == cell_y)
      {
	 //We have found our target piece.

	 //Either we don't have to jump a piece, or the piece in question has a jump available.
	 if (!must_jump || possible_moves[i].jumped_pieces.size() > 0)
	 {
	    return true;
	 }
      }
   }

   if (must_jump)
   {
      this->status = "There is a jump that must be made.";
   }

   return false; //The piece at the given cell cannot be moved.
}

std::vector<PieceMove> GameSimulator::getPossibleMoves(PLAYER player) const
{
   //Keep in mind that PLAYER1 is the top player, and therefore must move downwards.
   //PLAYER2 is the bottom player, and therefore must move upwards. But king pieces
   //can move either up or down (diagonally, that is).

   PLAYER opponent = player == PLAYER1 ? PLAYER2 : PLAYER1;

   std::vector<PieceMove> moves;
   
   for (unsigned int x = 0; x < 8; x++)
   {
      for (unsigned int y = 0; y < 8; y++)
      {
	 if (this->cell_data[x][y].player != player)
	 {
	    //This cell isn't occupied by the current player.

	    continue;
	 }

	 //We've found a cell which is occupied by the current player. Let's check if
	 //there are any moves which must be made.

	 std::vector<int> check_y_displacement;

	 if (this->cell_data[x][y].is_king)
	 {
	    //The piece can move either up or down

	    check_y_displacement.push_back(-1);
	    check_y_displacement.push_back(1);
	 }
	 else
	 {
	    if (player == PLAYER1)
	    {
	       //The piece can move down
	       check_y_displacement.push_back(1);
	    }
	    else
	    {
	       //The piece can move up
	       check_y_displacement.push_back(-1);
	    }
	 }

	 for (unsigned int i = 0; i < check_y_displacement.size(); i++)
	 {
	    unsigned int new_y1 = y + check_y_displacement[i]; //The tile (y) to jump over or on
	    if (new_y1 >= 8)
	    {
	       continue;
	    }

	    //Let's check for moves to empty spaces (no jumping pieces).

	    if (x > 0)
	    {
	       if (this->cell_data[x - 1][new_y1].player == NONE)
	       {
		  UIntPoint start(x, y);
		  UIntPoint end(x - 1, new_y1);

		  moves.push_back(PieceMove(start, end));
	       }
	    }

	    if (x < 7)
	    {
	       if (this->cell_data[x + 1][new_y1].player == NONE)
	       {
		  UIntPoint start(x, y);
		  UIntPoint end(x + 1, new_y1);

		  moves.push_back(PieceMove(start, end));
	       }
	    }
	    
	    //Let's check for piece jumps.
	    
	    unsigned int new_y2 = y + check_y_displacement[i] * 2; //The tile (y) to land on
	    if (new_y2 >= 8)
	    {
	       //We don't have to check for negatives since new_y is unsigned.
	       
	       continue;
	    }
	    
	    if (x > 1)
	    {
	       if (this->cell_data[x - 1][new_y1].player == opponent && this->cell_data[x - 2][new_y2].player == NONE)
	       {
		  //Found a jump to the left

		  UIntPoint start(x, y);
		  UIntPoint end(x - 2, new_y2);

		  PieceMove move(start, end);

		  move.jumped_pieces.push_back(UIntPoint(x - 1, new_y1));

		  moves.push_back(move);
	       }
	    }

	    if (x < 6)
	    {
	       if (this->cell_data[x + 1][new_y1].player == opponent && this->cell_data[x + 2][new_y2].player == NONE)
	       {
		  //Found a jump to the right

		  UIntPoint start(x, y);
		  UIntPoint end(x + 2, new_y2);

		  PieceMove move(start, end);

		  move.jumped_pieces.push_back(UIntPoint(x + 1, new_y1));

		  moves.push_back(move);
	       }
	    }
	 }
      }
   }

   return moves;
}

void GameSimulator::postMove(bool jump_made)
{
   if (jump_made)
   {
      if (this->player_turn == PLAYER1)
      {
	 this->player1_pieces_captured++;
      }
      else if (this->player_turn == PLAYER2)
      {
	 this->player2_pieces_captured++;
      }
   }
   
   //Check for kinging.
   unsigned int king_row = this->player_turn == PLAYER1 ? 7 : 0;
   for (unsigned int x = 0; x < 8; x++)
   {
      if (this->cell_data[x][king_row].player == this->player_turn)
      {
	 this->cell_data[x][king_row].is_king = true;
      }
   }

   std::vector<PieceMove> possible_moves = getPossibleMoves(this->player_turn);
   
   //Check if the current player still has jumps which must be made.
   bool must_jump = false;

   if (jump_made)
   {
      for (unsigned int i = 0; i < possible_moves.size(); i++)
      {
	 //Find the piece we just used for the jump.
	 if (possible_moves[i].start_pos.x != this->selected_cell[0] || possible_moves[i].start_pos.y != this->selected_cell[1])
	 {
	    continue;
	 }

	 //We've found the piece we just used for the jump. Now let's check if we can do further jumps with it.
      
	 if (possible_moves[i].jumped_pieces.size() > 0)
	 {
	    must_jump = true;

	    break;
	 }
      }
   }

   if (must_jump)
   {
   this->must_move_cell[0] = this->selected_cell[0];
   this->must_move_cell[1] = this->selected_cell[1];
   }
   else
   {
      this->must_move_cell[0];
      this->must_move_cell[1];
   }

   if (!must_jump || !jump_made)
   {
      if (this->player_turn == PLAYER1)
      {
	 this->player_turn = PLAYER2;
      }
      else
      {
	 this->player_turn = PLAYER1;
      }

      this->status = "Please make a move.";

      this->selected_cell[0] = this->selected_cell[1] = -1;
      this->must_move_cell[0] = this->must_move_cell[1] = -1;

      if (getPossibleMoves(this->player_turn).size() == 0)
      {
	 //Notice: The turn has switched to the loser.
	 if (player_turn == PLAYER1)
	 {
	    this->status = std::string("VICTORY FOR PLAYER 2!");
	 }
	 else
	 {
	    this->status = std::string("VICTORY FOR PLAYER 1!");
	 }

	 this->player_turn = NONE;
      }
   }
   else
   {
      this->must_move_cell[0] = this->selected_cell[0];
      this->must_move_cell[1] = this->selected_cell[1];

      this->status = "We must continue jumping.";
   }
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
