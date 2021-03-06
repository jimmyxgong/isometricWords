/* Author: Jimmy X Gong
 * File Name: letterArray.hpp
 * Description: header file for letterArray.cpp
 */

#ifndef LETTERARRAY_HPP
#define LETTERARRAY_HPP

const int NUM_LETTERS = 26;

#include <iostream>
#include "isoLetters.hpp"

class letterArray{

	public:
		letterArray();

		~letterArray();

		isoLetters *letterA[NUM_LETTERS];

		void makeArray();
};

#endif //LETTERARRAY_HPP