/* Author: Jimmy X. Gong
 * File Name: isoLetters.cpp
 * Description: A class that holds a letter and its drawing member functions
 */

#include <iostream>
#include <fstream>
#include <string>
#include "isoLetters.hpp"
 
/* ===== constructor ===== */
isoLetters::isoLetters( char iso_L ){
    this->letter = iso_L;
}

/* ===== deconstructor ===== */
isoLetters::~isoLetters(){}


/* ===== member function implementations ===== */

/* Prints out one line from the text font file of a letter
 * ARGS: 
 *      arg 1: place -- varies from 1-11. Defines which line of letter to print 
 */
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

/* Prints out the line from font text file of a letter */
void isoLetters::drawVert(){
    std::ifstream fontFile( "fonts/isometric4.txt" );
    std::string line;

    if(!fontFile) std::cerr << "Could not open the file!" << std::endl;

    int ascii = this->letter - ASCII_BUF;
    int position = (ascii*MAXHEIGHT);
    int count = 0;
    
    while( std::getline(fontFile, line) ){
        if( count == position ){
            std::cout << line << std::endl;
            for( int i = 0; i < 10; i++ ){
                std::getline(fontFile, line);
                std::cout << line << std::endl;
            }
        } 
        count++;
    }
}

/* Returns the line in place to draw
 * ARGS:
 *      arg 1: place -- varies from 1-11. Defines which line of letter to print
 * RETURN: a string from font text file that is to be printed
 */
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
