
#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <iostream>


class BinaryHeap {

	int* arr; // not resized
	int length; // maxium ammount of elements in array
	int size; // number of inserted elements

public:

	BinaryHeap(int* arr, int size);
	~BinaryHeap();


	// adds element to the heap
	// throws exception if next inserted element would exceed bound of the array
	void add(int element);

	
	// removes first element of designated value
	void remove(int element);


	// returns true if element is in the heap
	bool search(int element);


	// restores heap invariant by bubbling up starting from designated index
	void bubbleUp(int index);

	// restores heap invariant by bubbling down starting from designated index
	void bubbleDown(int index);


	// returns parent index
	int getParentIndex(int index);

	// returns left child index
	int getLeftChildIndex(int index);

	// returns right child index
	int getRightChildIndex(int index);


	// returns size
	int getSize();


	// prints array
	void print();
};

#endif
