
#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <iostream>
#include <iomanip>

#include "Exceptions.h"

class BinaryHeap {

	int* arr; // not resized
	int length; // maxium ammount of elements in array
	int size; // number of inserted elements

public:

	BinaryHeap(int* arr, int size);
	~BinaryHeap();


	// adds element to the heap
	// throws OUT_OF_SPACE exception if next inserted element would exceed bound of the array
	void add(int element);

	
	// removes first element of designated value
	// throws NOT_FOUND exception if element is not in the heap
	void remove(int element);


	// returns true if element is in the heap
	bool search(int element);


	// restores heap invariant by bubbling up starting from designated index
	void bubbleUp(int index);

	// restores heap invariant by bubbling down starting from designated index
	void bubbleDown(int index);

	// returns parent index
	int getParent(int index);

	// returns left child index
	int getLeftChild(int index);

	// returns right child index
	int getRightChild(int index);

	// returns size
	int getSize();

	// returns element at index 0
	// throws EMPTY exception if heap is empty
	int peek();


	// prints heap shaped like a tree
	void print();
};

#endif
