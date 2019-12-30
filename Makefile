
all:
	g++ -g3 -o sample src/main.cpp -I include/ -I ~/include/ -std=gnu++11

clean:
	$(RM) sample *.o *~
