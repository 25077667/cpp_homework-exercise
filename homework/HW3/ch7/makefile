CC = g++
target1 = p1
target2 = p5
target3 = p6
target4 = p8
target5 = p11
CFLAGS = -Wall -g -O3 -Os -std=c++11
shellCommand := $(shell find . -type f -print0 | xargs -0 dos2unix)

all: *.cpp
	$(CC) $(CFLAGS) -o $(target1) $(target1).cpp
	$(CC) $(CFLAGS) -o $(target2) $(target2).cpp
	$(CC) $(CFLAGS) -o $(target3) $(target3).cpp pizza.h pizza.cpp
	$(CC) $(CFLAGS) -o $(target4) $(target4).cpp
	$(CC) $(CFLAGS) -o $(target5) $(target5).cpp

#reference : https://hackmd.io/s/SySTMXPvl