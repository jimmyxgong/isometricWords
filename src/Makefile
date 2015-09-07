# simple makefile for compilation of the program

CC=g++
CXXFLAGS=-std=c++11

isoLetters: isoLetters.o letterArray.o
	g++ -o isometricWords isoLetters.o letterArray.o main.cpp

isoLetters.o: isoLetters.hpp isoLetters.cpp

letterArray.o: isoLetters.hpp isoLetters.cpp letterArray.hpp letterArray.cpp