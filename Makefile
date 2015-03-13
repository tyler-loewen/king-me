CFLAGS = -I /home/lib2720/allegro5/include/ -std=c++0x
LIBDIR = /home/lib2720/allegro5/lib/
LNFLAGS = -lallegro -lallegro_primitives
OBJECTS = Main.o

king_me: $(OBJECTS)
	g++ -L $(LIBDIR) -o $@ $^ $(LNFLAGS) 

%.o : src/%.cc
	g++ $(CFLAGS) -c $^

clean:
	rm -rf *~ *.o king_me
