#include <iostream>
#include <string>
#include <memory>
#include <cppunit/ui/text/TestRunner.h>
#include "Display.h"
#include "GameSimulator.h"
#include "DefaultBoard.h"
#include "PlayerOnePiece.h"
#include "PlayerTwoPiece.h"
#include "DefaultHUD.h"
#include "SelectedCellHighlight.h"
#include "DefaultRuleSet.h"

int main()
{
 
   Display display(std::string("King Me!"), 700, 600);

   std::shared_ptr<GameSimulator> simulator = std::make_shared<GameSimulator>(display, 30);

   std::shared_ptr<BoardInterface> board_ptr = std::make_shared<DefaultBoard>(display);

   std::shared_ptr<HUDInterface> hud_ptr = std::make_shared<DefaultHUD>();

   std::shared_ptr<HighlightCellInterface> highlight_selected_ptr = std::make_shared<SelectedCellHighlight>();

   std::shared_ptr<RuleSetInterface> rule_set_ptr = std::make_shared<DefaultRuleSet>();

   simulator->setBoard(board_ptr);
   simulator->setHUD(hud_ptr);
   simulator->setSelectedCellHighlight(highlight_selected_ptr);
   simulator->setRuleSet(rule_set_ptr);

   std::shared_ptr<PieceInterface> player1_piece = std::make_shared<PlayerOnePiece>();

   std::shared_ptr<PieceInterface> player2_piece = std::make_shared<PlayerTwoPiece>();

   simulator->setPlayerOnePiece(player1_piece);
   simulator->setPlayerTwoPiece(player2_piece);

   simulator->run();
   
   return 0;
}
