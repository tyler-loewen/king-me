CFLAGS = -I /home/lib2720/allegro5/include/ -std=c++0x
LIBDIR = /home/lib2720/allegro5/lib/
LNFLAGS = -lallegro -lallegro_primitives -lcppunit -ldl
OBJECTS = Main.o Simulator.o GameSimulator.o Display.o DefaultBoard.o PlayerOnePiece.o PlayerTwoPiece.o GameSimulatorTestFixture.o SelectedCellHighlight.o

king_me: $(OBJECTS)
	g++ -L $(LIBDIR) -o $@ $^ $(LNFLAGS) 

%.o : src/%.cc
	g++ $(CFLAGS) -c $^

clean:
	rm -rf *# *~ *.o src/*~ src/*# king_me
