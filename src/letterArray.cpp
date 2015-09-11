/* Author: Jimmy X. Gong
 * File Name: letterArray.cpp
 * Description: TODO
 */

 #include  <iostream>
 #include "isoLetters.hpp"
 #include "letterArray.hpp"

// constructor
letterArray::letterArray(){}

//deconstructor
letterArray::~letterArray(){}

// member function implementations
void letterArray::makeArray(){
	for( int i = 0; i<NUM_LETTERS; i++ ){
		this->letterA[i] = new isoLetters( i + ASCII_BUF );  
	}
}