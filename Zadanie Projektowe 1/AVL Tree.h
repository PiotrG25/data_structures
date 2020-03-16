
#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>


class AVLTree {
	struct Node {
		int value;
		Node* left, * right;

		// contains the difference in height of the right subtree and the left subtree
		int balancedFactor; 

		Node(int value);
	};


	Node* root;
	int size;


	// deletes node and its subtrees
	void deleteSubtree(Node* n);

public:

	AVLTree(int* arr, int n);
	~AVLTree();


	// adds element to the tree
	void add(int element);

	// removes element from the tree
	void remove(int element);

	// returns true if element is in the tree
	bool search(int element);
};

#endif
