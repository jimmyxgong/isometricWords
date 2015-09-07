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
	std::ifstream fontFile( "../fonts/isometric4.txt" );
	std::ofstream outFile;
	outFile.open( "result.txt" );
    std::string line;

    if (!fontFile) std::cerr << "Could not open the file!" << std::endl;

	int ascii = this->letter - ASCII_BUF;
	int position = (ascii*MAXHEIGHT)+place;		// location to copy
    int count = 0;

    // copying line from font file into output file
    while(std::getline(fontFile, line)){
    	if( count == position ){
    		std::cout<< line;
    		//outFile<<line<<std::flush;
    		break;
    	}
    	count++;
    }
    outFile.close();
    fontFile.close();
    
}

void isoLetters::drawVert( int place ){
	//TODO
}

char isoLetters::getLetter(){
	return this->letter;
}