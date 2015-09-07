/* Author: Jimmy X Gong
 * File Name: letterArray.hpp
 * Description:
 */

#ifndef LETTERARRAY_HPP
#define LETTERARRAY_HPP

#include <iostream>
#include "isoLetters.hpp"

class letterArray{

	public:
		letterArray(){};
		
		isoLetters *letterA[25];

		void makeArray();
};

#endif //LETTERARRAY_HPP