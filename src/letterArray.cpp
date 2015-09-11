/* Author: Jimmy X. Gong
 * File Name: letterArray.cpp
 * Description: A simple class that acts as a wrapper for an isoLetter array
 */

 #include  <iostream>
 #include "isoLetters.hpp"
 #include "letterArray.hpp"

/* ===== constructor =====*/
letterArray::letterArray(){}

/* ===== deconstructor =====*/
letterArray::~letterArray(){}

/* ===== member function implementations ===== */

/* Creates an array of isoLetters from letter a - z */
void letterArray::makeArray(){
	for( int i = 0; i<NUM_LETTERS; i++ ){
		this->letterA[i] = new isoLetters( i + ASCII_BUF );  
	}
}