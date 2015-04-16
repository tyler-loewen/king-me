#include <string>
#include <iostream>
#include "DefaultBoard.h"
#include "GameSimulatorTestFixture.h"
#include "SelectedCellHighlight.h"

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
