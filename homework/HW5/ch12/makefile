CC = g++
target1 = p2
target2 = p3
target2 = p5
flags = -Wall -g -O3 -Os -std=c++11

all: *.cpp
	$(CC) $(flags) -o $(target1) $(target1).cpp
	$(CC) $(flags) -o $(target2) $(target2).cpp
	$(CC) $(flags) -o $(target3) $(target3).cpp

clean: *.o
	rm -rf *.o
	rm -rf *.gch