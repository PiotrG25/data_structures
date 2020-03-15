
#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>

#include "Exceptions.h"

class DoublyLinkedList {
	struct Node {
		int value;
		Node *left, *right;

		Node(int value);
	};

	Node *head, *tail;
	int size;

public:

	DoublyLinkedList(int* arr, int size);


	// adds element at the beginning
	void addFirst(int element);

	// adds element at the end
	void addLast(int element);

	// adds element at designated index
	void addAt(int element, int index);


	// removes first element
	void removeFirst();

	// removes last element
	void removeLast();

	// removes element at designated index
	void removeAt(int index);

	// removes first element of designated value
	void remove(int element);


	// returnes true if element is in the list
	bool search(int element);

	// returns index of first element of designated value
	// -1 if not found
	int find(int element);

	// return size
	int getSize();

	// prints list forwart in the first line and backward in the second
	// each to elementsare separated by a single space
	void print();
};

#endif
