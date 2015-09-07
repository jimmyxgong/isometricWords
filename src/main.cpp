/* Author: Jimmy X Gong
 * File Name: main.cpp
 * Description: TODO
 */

#include <iostream>
#include <string>
#include "isoLetters.hpp"
#include "letterArray.hpp"

int main(){
	bool horizontal = false;
	char orietation;
	string message;

	std::cout << "Please type in your message" << std::end;
	std::cin >> message;
	std::cout << "Horizontal orietation? (y/n)" << std::endl;
	std::cin >> orietation;

	return 0;
}