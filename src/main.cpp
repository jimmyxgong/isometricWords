/* Author: Jimmy X Gong
 * File Name: main.cpp
 * Description: TODO
 */

#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string>
#include "isoLetters.hpp"
#include "letterArray.hpp"

int main(){
	bool horizontal = false;
	char orietation;
	int stringLength;
	std::string message;

	std::cout << "Please type in your message" << std::endl;
	std::cin >> message;
	std::cout << "Horizontal orientation? (y/n)" << std::endl;
	std::cin >> orietation;

	stringLength = message.length();

	// creating the isoLetter array
	letterArray *letters = new letterArray();
	letters->makeArray();

	// converts to uppercase
	for( int i = 0; i < message.length(); i++ ){
		message[i] = toupper(message[i]);
	}

	if( orietation == 'y' || orietation == 'Y' ){
		std::string::iterator it;

		for( int i = 0; i<MAXHEIGHT; i++ ){
			for( it = message.begin(); it < message.end() ; it++ ){
				char currChar = *it;

				if( currChar == ' ' ){
//					std::cout<< " ";
					continue;
				}

				int currVal = currChar - ASCII_BUF;
				letters->letterA[currVal]->drawHoriz( i );
			}
			std::cout << std::endl;
		}
	}

	return 0;
}