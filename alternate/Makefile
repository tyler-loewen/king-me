CFLAGS = -I /home/lib2720/allegro5/include/ -std=c++0x
LIBDIR = /home/lib2720/allegro5/lib/
OBJECTS = AlternateRuleSet.o AlternateHUD.o AlternateMain.o Simulator.o GameSimulator.o Display.o AlternateBoard.o AlternatePlayerOnePiece.o AlternatePlayerTwoPiece.o AlternateCellHighlight.o
LNFLAGS = -lallegro -lallegro_primitives -lallegro_image -lcppunit -ldl -lallegro_font -lallegro_ttf

king_me2: $(OBJECTS)
	g++ -L $(LIBDIR) -o $@ $^ $(LNFLAGS) 

%.o : ../src/%.cc
	g++ $(CFLAGS) -c $^

clean:
	rm -rf *# *~ *.o src/*~ src/*# king_me2
