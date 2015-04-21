#include <iostream>
#include <string>
#include <memory>
#include <cppunit/ui/text/TestRunner.h>
#include "Display.h"
#include "GameSimulator.h"
#include "AlternateBoard.h"
#include "AlternatePlayerOnePiece.h"
#include "AlternatePlayerTwoPiece.h"
#include "AlternateHUD.h"
#include "AlternateCellHighlight.h"
#include "AlternateRuleSet.h"

int main()
{
 
   Display display(std::string("King Me!"), 700, 600);

   std::shared_ptr<GameSimulator> simulator = std::make_shared<GameSimulator>(display, 30);

   std::shared_ptr<BoardInterface> board_ptr = std::make_shared<AlternateBoard>(display);

   std::shared_ptr<HUDInterface> hud_ptr = std::make_shared<AlternateHUD>();

   std::shared_ptr<HighlightCellInterface> highlight_selected_ptr = std::make_shared<AlternateCellHighlight>();

   std::shared_ptr<RuleSetInterface> rule_set_ptr = std::make_shared<AlternateRuleSet>();

   simulator->setBoard(board_ptr);
   simulator->setHUD(hud_ptr);
   simulator->setSelectedCellHighlight(highlight_selected_ptr);
   simulator->setRuleSet(rule_set_ptr);

   std::shared_ptr<PieceInterface> player1_piece = std::make_shared<AlternatePlayerOnePiece>();

   std::shared_ptr<PieceInterface> player2_piece = std::make_shared<AlternatePlayerTwoPiece>();

   simulator->setPlayerOnePiece(player1_piece);
   simulator->setPlayerTwoPiece(player2_piece);

   simulator->run();
   
   return 0;
}
