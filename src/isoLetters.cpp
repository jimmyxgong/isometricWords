/* Author: Jimmy X. Gong
 * File Name: isoLetters.cpp
 * Description: TODO
 */

#include <iostream>
#include <fstream>
#include <string>
#include "isoLetters.hpp"
 
// constructor
isoLetters::isoLetters( char iso_L ){
	this->letter = iso_L;
}

// member function implementations
void isoLetters::drawHoriz( int place ){
	std::ifstream fontFile( "fonts/isometric4.txt" );
    std::string line;

    if (!fontFile) std::cerr << "Could not open the file!" << std::endl;

	int ascii = this->letter - ASCII_BUF;
	int position = (ascii*MAXHEIGHT)+place;		// location to copy
    int count = 0;

    // copying line from font file into output file
    while( std::getline(fontFile, line) ){
    	if( count == position ){
    		std::cout<< line;
    		break;
    	}
    	count++;
    }
    fontFile.close();
}

void isoLetters::drawVert( int place ){
	//TODO
}

std::string isoLetters::lineToDraw( int place ){
    std::ifstream fontFile( "fonts/isometric4.txt" );
    std::string line;
    if(!fontFile) std::cerr << "Could not open the file!" << std::endl;

    int ascii = this->letter - ASCII_BUF;
    int position = (ascii*MAXHEIGHT)+place;     // location to copy
    int count = 0;

    while( std::getline(fontFile, line) ){
        if( count == position ){
            fontFile.close();
            return line;
        }
        count++;
    }
    fontFile.close();
    return line;
}

char isoLetters::getLetter(){
	return this->letter;
}
