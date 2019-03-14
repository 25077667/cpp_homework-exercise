CC = g++
target1 = p4
target2 = p8
target3 = p10
target5 = p14
CFLAGS = -Wall -g -O3 -std=c++11
shellCommand := $(shell find . -type f -print0 | xargs -0 dos2unix)

all: *.cpp
	$(CC) $(CFLAGS) -o $(target1) $(target1).cpp
	$(CC) $(CFLAGS) -o $(target2) $(target2).cpp
	$(CC) $(CFLAGS) -o $(target3) $(target3).cpp
	$(CC) $(CFLAGS) -o $(target5) $(target5).cpp

#reference : https://hackmd.io/s/SySTMXPvl