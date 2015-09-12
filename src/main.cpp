/* Author: Jimmy X Gong
 * File Name: main.cpp
 * Description: Main program driver for isometricWords
 */

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <ctype.h>
#include <string>
#include "isoLetters.hpp"
#include "letterArray.hpp"

/* ===== Static variable declartions ===== */
static int MAXDISPLAYLENGTH = 12;
static char saveToFile;
static char h_orientation;
static int stringLength;
static bool exit_P = false;

/* ===== Static function declarations ===== */

static std::string toUpperCase( std::string message );
static void messageCheck( std::string message );
static void horizontalMessage( letterArray *letters, std::string message );
static void verticalMessage( letterArray *letters, std::string message );
static void saveHorizontalMessage( letterArray *letters, std::string message, std::ofstream& outFile );
static void saveVerticalMessage( letterArray *letters, std::string message, std::ofstream& outFile );
static void cleanUp( letterArray *letters );

/* ===== Main program  ===== */
int main(){
	std::string message;
	std::ofstream outFile( "output.txt" );

	std::cout << "Please type in your message" << std::endl;
	std::getline(std::cin, message);
	
	stringLength = message.length();

	// creating the isoLetter array
	letterArray *letters = new letterArray();
	letters->makeArray();

	// converts message to all uppercase
	message = toUpperCase( message );

	// checks if valid message
	while( exit_P == false ){
		messageCheck( message );
		if( exit_P == false ){
			std::getline(std::cin, message);
			message = toUpperCase( message );
		}
	}

	std::cout << "Horizontal orientation? (y/n)" << std::endl;
	std::cin >> h_orientation;
	
	// translates in horizontal or vertical orientation
	horizontalMessage( letters, message );
	verticalMessage( letters, message );
	
	std::cout << "Save message to a text file? (y/n)" << std::endl;
	std::cin >> saveToFile;

	if( h_orientation == 'y' || h_orientation == 'Y'){
		saveHorizontalMessage( letters, message, outFile );
	} else if( h_orientation == 'n' || h_orientation == 'N' ){
		saveVerticalMessage( letters, message, outFile );
	}

	// Cleaning up memory leaks
	cleanUp( letters );

	return 0;
}

/* ===== Static function implementations ===== */

/* Converts the message into all uppercase 
 * ARGS:
 *		arg 1: message -- string to be put in all upper case
 * RETURN: returns uppercase message
*/
static std::string toUpperCase( std::string message ){
	for( int i = 0; i < message.length(); i++ ){
		message[i] = toupper(message[i]);
	}

	return message;
}

/* Checks if inputted message is valid */
static void messageCheck( std::string message ){
	std::string::iterator it;

	for( it = message.begin(); it < message.end(); it++ ){
		int charNum = *it;
		if( (charNum != 32) && ( (charNum < 64) || (charNum > 90) ) ){
			std::cout << "Invalid message." << std::endl;
			std::cout << "Please type a message only with a-z, A-Z characters." << std::endl;
			exit_P = false;
			return;
		} else{ exit_P = true; }
	}
}

/* Prints out the message in isometric font in a horizontal orientation 
 * ARGS: 
 *		arg 1: *letters -- letterArray that holds the isoLetter arrays
 *		arg 2: message -- message to be translated
 *
*/
static void horizontalMessage( letterArray *letters, std::string message ){
	if( message.length()<MAXDISPLAYLENGTH && ( h_orientation== 'y' || h_orientation == 'Y')  ){
		std::string::iterator it;

		for( int i = 0; i<MAXHEIGHT; i++ ){
			for( it = message.begin(); it < message.end(); it++ ){
				char currChar = *it;

				// taking care of spaces
				if( currChar == ' ' ){
					std::cout<< "                ";
					continue;
				}

				int currVal = currChar - ASCII_BUF;
				letters->letterA[currVal]->drawHoriz( i );
			}
			std::cout << std::endl;		
		}
	} else if( message.length() > MAXDISPLAYLENGTH ){
		std::cout << "Your message exceeded maximum display characters ("
			<< message.length() << "). Will not display on terminal." << std::endl;
	}
}

/* Prints out the message in isometric font in a vertical orientation 
 * ARGS: 
 *		arg 1: *letters -- letterArray that holds the isoLetter arrays
 *		arg 2: message -- message to be translated
 *
*/
static void verticalMessage( letterArray *letters, std::string message ){
	if( h_orientation == 'n' || h_orientation == 'N' ){
		std::string::iterator it;

		for( it = message.begin(); it < message.end(); it++ ){
			 char currChar = *it;

			 if( currChar == ' '){
			 	std::cout<<'\n';
			 	continue;
			 }
			 int currVal = currChar - ASCII_BUF;
			 letters->letterA[currVal]->drawVert();
		}
	}
}

/* Saves the message to an outfile in isometric font in a horizontal orientation 
 * ARGS: 
 *		arg 1: *letters -- letterArray that holds the isoLetter arrays
 *		arg 2: message -- message to be translated
 *		arg 3: outFile -- ofstream of the output file
 *
*/
static void saveHorizontalMessage( letterArray *letters, std::string message, std::ofstream& outFile ){
	if( saveToFile == 'y' || saveToFile == 'Y' ){
		std::cout << "NOTE: Text editor must have word wrap disabled to properly display longer sentences." << std::endl;
		std::string::iterator it;

		for( int i = 0; i<MAXHEIGHT; i++ ){
			for( it = message.begin(); it < message.end(); it++ ){
				char currChar = *it;
				if( currChar == ' ' ){
					outFile << "                ";
					continue;
				}

				std::string toDraw;
				int currVal = currChar - ASCII_BUF;
				toDraw = letters->letterA[currVal]->lineToDraw( i );
				outFile<<toDraw;
			}
			outFile<<'\n';
		}
		outFile.close();

		std::cout << "Saved to file output.txt" << std::endl;
	}	
}

/* Saves the message to an outfile in isometric font in a vertical orientation 
 * ARGS: 
 *		arg 1: *letters -- letterArray that holds the isoLetter arrays
 *		arg 2: message -- message to be translated
 *		arg 3: outFile -- ofstream outfile for the translated message
 *
*/
static void saveVerticalMessage( letterArray *letters, std::string message, std::ofstream& outFile ){
	if( saveToFile == 'y' || saveToFile == 'Y' ){
		std::string::iterator it;

		for( it = message.begin(); it < message.end(); it++ ){
			char currChar = *it;
			for( int i = 0; i < MAXHEIGHT; i++ ){
				if( currChar == ' ' ){
					outFile << "\n\n\n\n";
					break;
				}
				std::string toDraw;
				int currVal = currChar - ASCII_BUF;
				toDraw = letters->letterA[currVal]->lineToDraw( i );
				outFile<<toDraw;
				outFile<<'\n';
			}
		}
		outFile.close();

		std::cout << "Saved to file output.txt" << std::endl;
	}
}

/* Takes care of unchecked pointers and memory leaks
 * ARGS: 
 *		arg 1: letters -- letterArray that needs to be cleaned 
 */
static void cleanUp( letterArray *letters ){
	for( int i = 0; i < NUM_LETTERS; i++ ){
		delete letters->letterA[i];
	}
	delete letters;
	letters = 0;
}
