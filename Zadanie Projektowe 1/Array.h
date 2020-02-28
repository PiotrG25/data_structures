
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

#include "Exceptions.h"

class Array {
	int* arr;
	int size;

public:

	Array(int* arr, int size);
	~Array();


	// resizes array and adds element at the beginning
	void addFirst(int element);

	// resizes array and adds element at the end
	void addLast(int element);

	// resizes array and adds element at designated index
	// throws OUT_OF_BOUND exception if index is out of {0, 1, 2, ... S} where S is size before resize
	void addAt(int element, int index);


	// removes element from the first position
	// throws EMPTY exception if array is empty
	void removeFirst();

	// removes element from the last position
	// throws EMPTY exception if array is empty
	void removeLast();

	// removes element at designated index and resizes array
	// throws EMPTY exception if array is empty
	// throws OUT_OF_BOUND exception if index if out of bound
	void removeAt(int index);


	// returns true if element is in the array
	bool search(int element);

	// returns size
	int getSize();

	// prints in one line elements from array separated by spaces
	void print();
};

#endif