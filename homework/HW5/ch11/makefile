CC = g++
target1 = p1
target2 = p3
flags = -Wall -g -O3 -Os -std=c++11

all: target_1 
	$(CC) $(flags) -o $(target1) f.o g.o $(target1).cpp
	#$(CC) $(flags) -o $(target2) f.o g.o $(target2).cpp

target_1: f.cpp f.h g.cpp g.h
	$(CC) -c f.cpp f.h
	$(CC) -c g.cpp g.h

#target_2:

clean: *.o
	rm -rf *.o
	rm -rf *.gch