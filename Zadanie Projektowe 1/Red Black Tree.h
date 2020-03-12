
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
	// return highest Node in the subtree
	Node* leftleftCase(Node* n);
	Node* leftRightCase(Node* n);
	Node* rightLeftCase(Node* n);
	Node* rightRightCase(Node* n);


	void removeLeaf(Node* n);
	void removeNodeWithLeftSubtree(Node* n);
	void removeNodeWithRightSubtree(Node* n);
	void removeNodeWithBothSubtrees(Node* n);


	// case describes position of red nephew in repation to n's parent
	void removeBlackLeafWithBlackSiblingRedNephewLeftLeftCase(Node* n);
	void removeBlackLeafWithBlackSiblingRedNephewLeftRightCase(Node* n);
	void removeBlackLeafWithBlackSiblingRedNephewRightLeftCase(Node* n);
	void removeBlackLeafWithBlackSiblingRedNephewRightRightCase(Node* n);

	// case describes position of n in relation to it's parent
	void removeBlackLeafWithBlackSiblingBlackNephewsLeftCase(Node* n);
	void removeBlackLeafWithBlackSiblingBlackNephewsRightCase(Node* n);

	void removeBlackLeafWithBlackSibling
	void removeBlackLeafWithBlackSibling
	void removeBlackLeafWith
	void removeBlackLeafWith
	void removeBlackLeaf
	void removeBlackLeaf
	void removeBlackLeaf


	void removeBlackNodeWithOneChildRedNephewLeftLeftCase(Node* n);
	void removeBlackNodeWithOneChildRedNephewLeftRightCase(Node* n);
	void removeBlackNodeWithOneChildRedNephewRightLeftCase(Node* n);
	void removeBlackNodeWithOneChildRedNephewRightRightCase(Node* n);
	void removeBlackNodeWithOneChild
	void removeBlackNodeWithOneChild
	void removeBlackNodeWithOneChild
	void removeBlackNodeWithOneChild

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
