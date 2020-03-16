
#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>


class AVLTree {
	struct Node {
		int value;
		Node* left, * right;

		// contains the difference in height of the right subtree and the left subtree
		int balancedFactor;

		// contains the number of layers below this node
		int height;

		Node(int value);
	};


	Node* root;
	int size;


	// deletes node and its subtrees
	void deleteSubtree(Node* n);


	// INSERTION cases

	void insert(Node* n, int value);
	void updane(Node* n);
	void rebalance(Node* n);

	// return the top node
	Node* rotateLeft(Node* n);
	Node* rotateRight(Node* n);

	Node* leftLeftCase(Node* n);
	Node* leftRightCase(Node* n);
	Node* rightLeftCase(Node* n);
	Node* rightRightCase(Node* n);


public:

	AVLTree(int* arr, int n);
	~AVLTree();


	// adds element to the tree
	// allows only unique values
	void add(int element);

	// removes element from the tree
	void remove(int element);

	// returns true if element is in the tree
	bool search(int element);
};

#endif
