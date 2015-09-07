/* Author: Jimmy X Gong
 * File Name: isoLetters.hpp
 * Description: TODO
 */

#ifndef ISOLETTERS_HPP
#define ISOLETTERS_HPP

const int MAXWIDTH = 15;
const int MAXHEIGHT = 11;
const int ASCII_BUF = 65;

#include <iostream>

class isoLetters{
	private:
		char letter;

	public:
		isoLetters( char iso_L );

		char getLetter();
		void drawHoriz( int place );
		void drawVert( int place );
};

#endif	//ISOLETTERS_HPP