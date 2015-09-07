/* Author: Jimmy X. Gong
 * File Name: isoLetters.cpp
 * Description: TODO
 */

#include <iostream>
#include <fstream>
 
int MAXWIDTH = 15;
int MAXHEIGHT = 11;
int ASCII_BUF = 65;

class isoLetters{

  private:
  	char letter;

  public:
  	isoLetters( char iso_L );

    char getLetter();
  	void drawHoriz( int place );
  	void drawVert();
};

// class constructor
isoLetters::isoLetters( char iso_L ){
	this->letter = iso_L;
}

//member function
void isoLetters::drawHoriz( int place ){
	std::ifstream fontFile( "../../fonts/isometric.txt" );
	std::ofstream outFile( "result.txt" );

	int ascii = this->letter - ASCII_BUF;
	int position = (ascii*MAXHEIGHT)+place;		// location to copy
}

void isoLetters::drawVert(){
	//TODO
}

char isoLetters::getLetter(){
	return this->letter;
}

int main(){
	char a = 'a';
	int aInt = 'a';
	std::cout << aInt << std::endl;
	return 0;
}
