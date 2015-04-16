#include <iostream>
#include <string>
#include <memory>
#include <cppunit/ui/text/TestRunner.h>
#include "Display.h"
#include "GameSimulator.h"
#include "DefaultBoard.h"
#include "PlayerOnePiece.h"
#include "PlayerTwoPiece.h"
#include "GameSimulatorTestFixture.h"
#include "DefaultHUD.h"

int main()
{
 
   Display display(std::string("King Me!"), 700, 600);

   std::shared_ptr<GameSimulator> simulator = std::make_shared<GameSimulator>(display, 30);

   std::shared_ptr<BoardInterface> board_ptr = std::make_shared<DefaultBoard>(display);

   std::shared_ptr<HUDInterface> hud_ptr = std::make_shared<DefaultHUD>();

   simulator->setBoard(board_ptr);
   simulator->setHUD(hud_ptr);

   std::shared_ptr<PieceInterface> player1_piece = std::make_shared<PlayerOnePiece>();

   std::shared_ptr<PieceInterface> player2_piece = std::make_shared<PlayerTwoPiece>();

   simulator->setPlayerOnePiece(player1_piece);
   simulator->setPlayerTwoPiece(player2_piece);

   simulator->run();

   std::cout << "Initializing tests." << std::endl;

   CppUnit::TextUi::TestRunner runner;

   runner.addTest(GameSimulatorTestFixture::suite());

   std::cout << "Test suite constructed. Running tests." << std::endl;
   
   runner.run();
   
   return 0;
}
