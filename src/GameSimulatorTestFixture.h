#ifndef GAMESIMULATORTESTFIXTURE_H
#define GAMESIMULATORTESTFIXTURE_H

#include <memory>
#include <cppunit/extensions/HelperMacros.h>
#include <stdexcept>
#include "GameSimulator.h"
#include "BoardInterface.h"

/**
 * A class used for testing the checkers game simulator.
 */
class GameSimulatorTestFixture : public CppUnit::TestFixture
{
   CPPUNIT_TEST_SUITE(GameSimulatorTestFixture);
   CPPUNIT_TEST(testClickCell);
   CPPUNIT_TEST_EXCEPTION(testClickCellOutOfBounds, std::out_of_range);
   CPPUNIT_TEST(testDrawCellHighlight);
   CPPUNIT_TEST_EXCEPTION(testDrawCellHighlightOutOfBounds, std::out_of_range);
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
    * Tests drawing a cell highlight with legal inputs. This should not result in any exceptions.
    */
   void testDrawCellHighlight();

   /**
    * Tests drawing a cell highlight with illegal inputs. This should result in an std::out_of_range exception.
    */
   void testDrawCellHighlightOutOfBounds();
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
};

#endif
