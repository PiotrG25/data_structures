
#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <iostream>

#include "Exceptions.h"

class RedBlackTree {
	struct Node {
		int value;
		bool red; // true if red, false if black
		Node *left, *right, *parent;

		Node(int value, bool red);
	};

	Node* root;
	int size;

	void restoreTreeInvariant(Node* n);

	void rotateRight(Node* n);
	void rotateLeft(Node* n);

	void leftleftCase(Node* n);
	void leftRightCase(Node* n);
	void rightLeftCase(Node* n);
	void rightRightCase(Node* n);

public:

	RedBlackTree(int * arr, int size);
	~RedBlackTree();

	void add(int element);

	void remove(int element);

	bool search(int element);


	void print();
};

#endif
