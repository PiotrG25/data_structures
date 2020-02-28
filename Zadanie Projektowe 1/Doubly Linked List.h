
#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>

#include "Exceptions.h"

class DoublyLinkedList {
	struct Node {
		int value;
		Node *left, *right;

		Node(int element) {
			this->value = element;
			this->left = NULL;
			this->right = NULL;
		}
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
	// throws OUT_OF_BOUND exception if index is out of {0, 1, 2, ... S} where S is size before insertion
	void addAt(int element, int index);


	// removes first element
	// throws EMPTY exception if list is empty
	void removeFirst();

	// removes last element
	// throws EMPTY exception if list is empty
	void removeLast();

	// removes element at designated index
	// throws EMPTY exception if list is empty
	// throws OUT_OF_BOUND exception if index is out of bound
	void removeAt(int index);

	// removes first element of designated value
	// throws NOT_FOUND exception if element is not in the list
	void remove(int element);


	// returnes true if element is in the list
	bool search(int element);

	// returns index of first element of designated value
	// throws NOT_FOUND exception if element is not in the list
	int find(int element);

	// return size
	int getSize();

	// prints list forwart in the first line and backward in the second
	// each to elementsare separated by a single space
	void print();
};

#endif
