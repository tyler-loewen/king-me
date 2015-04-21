#include <string>
#include <iostream>
#include "DefaultBoard.h"
#include "GameSimulatorTestFixture.h"
#include "SelectedCellHighlight.h"
#include "DefaultRuleSet.h"

GameSimulatorTestFixture::~GameSimulatorTestFixture()
{
   this->board.reset();
   
   if (this->simulator != NULL)
   {
      delete this->simulator;

      this->simulator = NULL;
   }

   if (this->display != NULL)
   {
      delete this->display;

      this->display = NULL;
   }
}

void GameSimulatorTestFixture::setUp()
{
   //Initialize the objects used for all/most tests.

   this->display = new Display(std::string("King Me! - Test"), 700, 600);
   this->simulator = new GameSimulator(*(this->display), 30);
   this->board = std::make_shared<DefaultBoard>(*(this->display), 255, 255, 255, 0, 0, 0);
   this->simulator->setBoard(this->board);
   this->selected_cell_highlight = std::make_shared<SelectedCellHighlight>();
   this->simulator->setSelectedCellHighlight(this->selected_cell_highlight);
   this->simulator->setRuleSet(std::make_shared<DefaultRuleSet>());
}

void GameSimulatorTestFixture::tearDown()
{
   this->board.reset();
   
   delete this->simulator;
   delete this->display;

   this->simulator = NULL;
   this->display = NULL;
}

void GameSimulatorTestFixture::testClickCell()
{
   this->simulator->clickCell(0, 0);
}

void GameSimulatorTestFixture::testClickCellOutOfBounds()
{
   this->simulator->clickCell(1000, 0);
}

void GameSimulatorTestFixture::testMove()
{
   this->simulator->clickCell(1, 2);

   this->simulator->clickCell(2, 3);

   CPPUNIT_ASSERT(this->simulator->cell_data[1][2].player == NONE);
   CPPUNIT_ASSERT(this->simulator->cell_data[2][3].player == PLAYER1);
}

void GameSimulatorTestFixture::testTurnSwitch()
{
   this->simulator->clickCell(1, 2);

   this->simulator->clickCell(2, 3);

   CPPUNIT_ASSERT(this->simulator->cell_data[1][2].player == NONE);
   CPPUNIT_ASSERT(this->simulator->cell_data[2][3].player == PLAYER1);
   CPPUNIT_ASSERT(this->simulator->player_turn == PLAYER2);
}

void GameSimulatorTestFixture::testJump()
{
   //Make a new enemy piece to jump over.
   this->simulator->cell_data[2][3] = BoardCellData(PLAYER2, false);
   
   this->simulator->clickCell(1, 2);

   this->simulator->clickCell(3, 4);

   CPPUNIT_ASSERT(this->simulator->cell_data[1][2].player == NONE);
   CPPUNIT_ASSERT(this->simulator->cell_data[2][3].player == NONE);
   CPPUNIT_ASSERT(this->simulator->cell_data[3][4].player == PLAYER1);
   CPPUNIT_ASSERT(this->simulator->player1_pieces_captured == 1);
}

void GameSimulatorTestFixture::testKinging()
{
   //Make a new enemy piece to jump over.
   this->simulator->cell_data[1][6] = BoardCellData(PLAYER1, false);
   this->simulator->cell_data[0][7] = BoardCellData(NONE, false);
   
   this->simulator->clickCell(1, 6);

   this->simulator->clickCell(0, 7);

   CPPUNIT_ASSERT(this->simulator->cell_data[0][7].is_king);
}

void GameSimulatorTestFixture::testVictory()
{
   for (unsigned int x = 0; x < 8; x++)
   {
      for (unsigned int y = 0; y < 8; y++)
      {
	 this->simulator->cell_data[x][y] = BoardCellData(NONE, false);
      }
   }

   this->simulator->cell_data[1][0] = BoardCellData(PLAYER1, false);
   this->simulator->cell_data[2][1] = BoardCellData(PLAYER2, false);
   
   this->simulator->clickCell(1, 0);

   this->simulator->clickCell(3, 2);

   CPPUNIT_ASSERT(this->simulator->status == std::string("VICTORY FOR PLAYER 1!"));
}
