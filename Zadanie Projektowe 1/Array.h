
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>


class Array {
	int* arr;
	int size;

public:

	Array(int* arr, int size);
	Array();
	~Array();


	// resizes array and adds element at the beginning
	void addFirst(int element);

	// resizes array and adds element at the end
	void addLast(int element);

	// resizes array and adds element at designated index
	void addAt(int element, int index);


	// removes first occurence of element
	void remove(int element);

	// removes element from the first position
	void removeFirst();

	// removes element from the last position
	void removeLast();

	// removes element at designated index and resizes array
	void removeAt(int index);


	// returns true if element is in the array
	bool search(int element);

	// returns index of element in the array
	// -1 if not found
	int find(int element);


	// returns size
	int getSize();

	// prints in one line elements from array separated by spaces
	void print();
};

#endif