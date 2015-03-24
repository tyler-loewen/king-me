#include <iostream> //TODO: Not needed
#include "GameSimulator.h"
#include "Display.h"

GameSimulator::GameSimulator(const Display &d, unsigned int fps):Simulator(d, fps)
{
   std::shared_ptr<MouseListener> mouse_listener = std::make_shared<GameMouseListener>(*this);
   std::shared_ptr<MouseMotionListener> mouse_motion_listener = std::make_shared<GameMouseMotionListener>(*this);

   addMouseListener(mouse_listener);
   addMouseMotionListener(mouse_motion_listener);

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
   al_clear_to_color(al_map_rgb(255, 0, 0));
   
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

   //Blah. Do the above later. Let's just add a single piece to test.

   //this->cell_data[0][0] = BoardCellData(PLAYER1, false);
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
