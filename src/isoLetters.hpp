/* Author: Jimmy X Gong
 * File Name: isoLetters.hpp
 * Description: Header file for isoLetters.cpp
 */

#ifndef ISOLETTERS_HPP
#define ISOLETTERS_HPP

#include <string>
 
const int MAXWIDTH = 15;
const int MAXHEIGHT = 11;
const int ASCII_BUF = 65;

#include <iostream>

class isoLetters{
	private:
		char letter;

	public:
		isoLetters( char iso_L );
		~isoLetters();
		char getLetter();
		void drawHoriz( int place );
		void drawVert();
		std::string lineToDraw( int place );
};

#endif	//ISOLETTERS_HPP