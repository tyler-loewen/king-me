CFLAGS = -I /home/lib2720/allegro5/include/ -std=c++0x
LIBDIR = /home/lib2720/allegro5/lib/
<<<<<<< HEAD
LNFLAGS = -lallegro -lallegro_primitives -lcppunit -ldl
OBJECTS = Main.o Simulator.o GameSimulator.o Display.o DefaultBoard.o PlayerOnePiece.o PlayerTwoPiece.o GameSimulatorTestFixture.o SelectedCellHighlight.o
=======
LNFLAGS = -lallegro -lallegro_primitives -lallegro_image -lcppunit -ldl
OBJECTS = DefaultHUD.o Main.o Simulator.o GameSimulator.o Display.o DefaultBoard.o PlayerOnePiece.o PlayerTwoPiece.o GameSimulatorTestFixture.o
>>>>>>> 6aa1aed2999275aa25149a56b456b0de58b558d6

king_me: $(OBJECTS)
	g++ -L $(LIBDIR) -o $@ $^ $(LNFLAGS) 

%.o : src/%.cc
	g++ $(CFLAGS) -c $^

clean:
	rm -rf *# *~ *.o src/*~ src/*# king_me
