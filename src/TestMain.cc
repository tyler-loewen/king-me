#include <iostream>
#include <cppunit/ui/text/TestRunner.h>
#include "GameSimulatorTestFixture.h"

int main()
{
   std::cout << "Initializing tests." << std::endl;

   CppUnit::TextUi::TestRunner runner;

   runner.addTest(GameSimulatorTestFixture::suite());

   std::cout << "Test suite constructed. Running tests." << std::endl;
   
   runner.run();
   
   return 0;
}
