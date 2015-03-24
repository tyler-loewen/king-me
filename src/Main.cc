#include <iostream>
#include <string>
#include <memory>
#include "Display.h"
#include "GameSimulator.h"
#include "DefaultBoard.h"
#include "PlayerOnePiece.h"
#include "PlayerTwoPiece.h"

int main()
{
 
   Display display(std::string("King Me!"), 700, 600);

   GameSimulator simulator(display, 30);

   std::shared_ptr<BoardInterface> board_ptr = std::make_shared<DefaultBoard>(display);

   simulator.setBoard(board_ptr);

   std::shared_ptr<PieceInterface> player1_piece = std::make_shared<PlayerOnePiece>();

   std::shared_ptr<PieceInterface> player2_piece = std::make_shared<PlayerTwoPiece>();

   simulator.setPlayerOnePiece(player1_piece);
   simulator.setPlayerTwoPiece(player2_piece);

   simulator.run();
   
   return 0;
}
