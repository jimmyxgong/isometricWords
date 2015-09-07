/* Author: Jimmy X Gong
 * File Name: letterArray.hpp
 * Description:
 */

#ifndef LETTERARRAY_HPP
#define LETTERARRAY_HPP

const int NUM_LETTERS = 25;

#include <iostream>
#include "isoLetters.hpp"

class letterArray{

	public:
		letterArray();

		isoLetters *letterA[NUM_LETTERS];

		void makeArray();
};

#endif //LETTERARRAY_HPP