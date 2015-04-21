#ifndef GAMESIMULATORTESTFIXTURE_H
#define GAMESIMULATORTESTFIXTURE_H

#include <memory>
#include <cppunit/extensions/HelperMacros.h>
#include <stdexcept>
#include "GameSimulator.h"
#include "BoardInterface.h"
#include "HighlightCellInterface.h"

/**
 * A class used for testing the checkers game simulator.
 */
class GameSimulatorTestFixture : public CppUnit::TestFixture
{
   CPPUNIT_TEST_SUITE(GameSimulatorTestFixture);
   CPPUNIT_TEST(testClickCell);
   CPPUNIT_TEST_EXCEPTION(testClickCellOutOfBounds, std::out_of_range);
   CPPUNIT_TEST(testMove);
   CPPUNIT_TEST(testTurnSwitch);
   CPPUNIT_TEST(testJump);
   CPPUNIT_TEST(testKinging);
   CPPUNIT_TEST(testVictory);
   CPPUNIT_TEST_SUITE_END();
   
  public:
   ~GameSimulatorTestFixture();

   /**
    * Gets the suite ready for every test case.
    */
   void setUp();

   /**
    * Destorys the testing data after every test case.
    */
   void tearDown();

   /**
    * Tests a cell click with legal inputs. This should not result in any exceptions.
    */
   void testClickCell();

   /**
    * Tests a cell click with illegal inputs. This should result in an std::out_of_range exception.
    */
   void testClickCellOutOfBounds();

   /**
    * Tests moving a piece.
    */
   void testMove();

   /**
    * Tests for turn switching after a move has been made.
    */
   void testTurnSwitch();

   /**
    * Tests if we can jump a piece, and checks if the pieces captured variable increments.
    */
   void testJump();

   /**
    * Checks if moving a piece to the end of the board (opposite side) turns the piece into a king.
    */
   void testKinging();

   /**
    * Tests for a victory for player one. The status should change to "VICTORY FOR PLAYER 1!" when player 1 wins.
    */
   void testVictory();
  private:
   /**
    * Pointer to the display object used in every test case.
    */
   Display *display;

   /**
    * Pointer to the game simulator used in every test case.
    */
   GameSimulator *simulator;

   /**
    * Smart pointer to the board object used in every test case.
    */
   std::shared_ptr<BoardInterface> board;

   /**
    * Smart pointer to the selected sell highlighter.
    */
   std::shared_ptr<HighlightCellInterface> selected_cell_highlight;
};

#endif
