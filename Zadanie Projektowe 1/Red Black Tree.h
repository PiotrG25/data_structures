
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

	void deleteNode(Node* n); // delete subtree


	void givenRedRestoreTreeInvariant(Node* n);

	// places n in place of its parent and:

	// replaces n's right subtree with parent and
	// parent's left subtree with n's right subtree
	void rotateRight(Node* n);
	// replaces n's left subtree with parent and
	// parends's right subtree with n's left subtree
	void rotateLeft(Node* n);


	// set of cases depending on possition of Node n
	// used only when n is red
	// n's parent is red
	// n's uncle is black
	Node* leftleftCase(Node* n);
	Node* leftRightCase(Node* n);
	Node* rightLeftCase(Node* n);
	Node* rightRightCase(Node* n);


	void removeCase1(Node* n);
	void removeCase2(Node* n);
	void removeCase3(Node* n);
	void removeCase4(Node* n);

public:

	RedBlackTree(int * arr, int size);
	~RedBlackTree();

	void add(int element);

	void remove(int element);

	


	bool search(int element);


	void print();
	void printNode(Node* n);
};

#endif
