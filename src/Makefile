# simple makefile for compilation of the program

CC= g++
CXX= g++
CXXFLAGS= -std=c++11

objects = isoLetters.o letterArray.o

isoLetters: isoLetters.o letterArray.o
	g++ -o isometricWords isoLetters.o letterArray.o main.cpp

isoLetters.o: isoLetters.hpp isoLetters.cpp

letterArray.o: isoLetters.hpp isoLetters.cpp letterArray.hpp letterArray.cpp

clean:
	rm -- $(objects)
