
#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>

#include "Exceptions.h"

class BinarySearchTree {
	struct Node {
		int value;
		Node *left, *right;

		Node(int value);
	};

	Node* root;
	int size;

	// deletes node and all of its children
	void deleteSubtree(Node* n);

	// REMOVAL cases
	void removeLeaf(Node* n, Node* parent);
	void removeNodeWithLeftSubtree(Node* n, Node* parent);
	void removeNodeWithRightSubtree(Node* n, Node* parent);

public:

	BinarySearchTree(int* arr, int size);
	~BinarySearchTree();


	// adds element to the tree
	// tree allows only unique values
	void add(int element);

	// removes element from the tree
	void remove(int element);

	// returns true if element is in the tree
	bool search(int element);


	// prints tree node by node
	void print();

	// prints value of the node, left child and right child
	// NULL if node does not exist
	// calls printNode for non NULL children
	void printNode(Node* n);

};

#endif
