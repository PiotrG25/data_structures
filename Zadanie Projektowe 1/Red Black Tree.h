
#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <iostream>

#include "Exceptions.h"

class RedBlackTree {
	struct Node {
		int value;
		bool red; // true if red, false if black
		Node *left, *right;

		Node(int value, bool red) {
			this->value = value;
			this->red = red;
			left = right = NULL;
		}
	};

	Node* root;
	int size;

public:

	RedBlackTree(int * arr, int size);
	~RedBlackTree();

	void add(int element);

	void remove(int element);

	bool search(int element);


	void print();
};

#endif
