
#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <iostream>


class RedBlackTree {
	struct Node {
		int value;
		bool red; // true if red, false if black
		Node *left, *right, *parent;

		Node(int value, bool red);
	};

	Node* root;
	int size;


	// deletes node and all of its children
	void deleteSubtree(Node* n);


	// ROTATIONS
	// places n in place of its parent and:

	// replaces n's right subtree with parent and
	// parent's left subtree with n's right subtree
	// n lands on top
	void rotateRight(Node* n);
	// replaces n's left subtree with parent and
	// parends's right subtree with n's left subtree
	// n lands on top
	void rotateLeft(Node* n);


	// INSERTION cases

	void givenRedRestoreTreeInvariant(Node* n);

	// set of cases depending on possition of Node n
	// used in restoring violation of tree invariant type red red
	// return highest Node in the subtree
	Node* redRedLeftleftCase(Node* n);
	Node* redRedLeftRightCase(Node* n);
	Node* redRedRightLeftCase(Node* n);
	Node* redRedRightRightCase(Node* n);


	// REMOVAL cases

	void givenDoubleBlackRestoreTreeInvariant(Node* n);

	// basic removal cases
	void removeLeaf(Node* n);
	void removeNodeWithLeftSubtree(Node* n);
	void removeNodeWithRightSubtree(Node* n);
	void removeNodeWithBothSubtrees(Node* n);


	// case describes position of red nephew in relation to n's parent
	void removeBlackLeafWithBlackSiblingRedNephewLeftLeftCase(Node* n);
	void removeBlackLeafWithBlackSiblingRedNephewLeftRightCase(Node* n);
	void removeBlackLeafWithBlackSiblingRedNephewRightLeftCase(Node* n);
	void removeBlackLeafWithBlackSiblingRedNephewRightRightCase(Node* n);

	// case describes position of n in relation to it's parent
	void removeBlackLeafWithBlackSiblingBlackNephewsLeftCase(Node* n);
	void removeBlackLeafWithBlackSiblingBlackNephewsRightCase(Node* n);
	void removeBlackLeafWithRedSiblingLeftCase(Node* n);
	void removeBlackLeafWithRedSiblingRightCase(Node* n);


	// repeted part of code
	// used after changing structure of subtree
	// connects top node of new subtree to parent of subtree
	void connectTopOfSubtreeToHigherNode(Node* top, Node* higher);

	// checks if node n and its parent aren't both red
	// compares heights of its subtrees
	// sets height to height of subtree including node n
	bool isCorrectSubtree(Node* n, int& height);


public:


	RedBlackTree(int * arr, int size);
	~RedBlackTree();

	// adds element to the tree
	// tree allows only unique values
	void add(int element);

	// removes element from the tree
	void remove(int element);

	// returns true if element is in the tree
	bool search(int element);

	// prints tree node by node
	void print();

	// prints value and color of node n
	// values of parent, left child and right child
	// NULL if node does not exist
	// calls printNode for non NULL children
	void printNode(Node* n);


	// checks tree invariant
	bool isCorrectTree();


	// returns size
	int getSize();
};

#endif
