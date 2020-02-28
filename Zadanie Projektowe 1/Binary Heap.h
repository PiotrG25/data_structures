
#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <iostream>

class BinaryHeap {

	int* arr;
	int length; // maxium ammount of elements in array
	int size; // number of inserted elements

public:

	BinaryHeap(int* arr, int size);


	// adds element to heap
	void add(int element);

	
	// removes first element of designated value
	// throws NOT_FOUND exception if element is not in the heap
	void remove(int element);



	// returns parent index
	int getParent(int index);

	// returns left child index
	int getLeftChild(int index);

	// returns right child index
	int getRightChild(int index);
};

#endif
