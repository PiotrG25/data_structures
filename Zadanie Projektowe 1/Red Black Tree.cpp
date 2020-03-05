
#include "Red Black Tree.h"

RedBlackTree::Node::Node(int value, bool red) {
	this->value = value;
	this->red = red;
	left = right = parent = NULL;
}

RedBlackTree::RedBlackTree(int * arr, int size) {
	this->size = 0;
	for (int i = 0; i < size; ++i) add(arr[i]);
}

RedBlackTree::~RedBlackTree() {

}


void RedBlackTree::add(int element) {

	if (size == 0) {
		root = new Node(element, false); // new black Node
		++size;
		return;
	}

	Node* n = root;
	while (true) {
		if (element < n->value) {
			if (n->left == NULL) {
				n->left = new Node(element, true);
				n->left->parent = n;
				n = n->left;
				break;
			}
			else n = n->left;
		}
		else {
			if (n->right == NULL) {
				n->right = new Node(element, true);
				n->right->parent = n;
				n = n->right;
				break;
			}
			else n = n->right;
		}
	}
	++size;

	restoreTreeInvariant(n);
}

void RedBlackTree::restoreTreeInvariant(Node* n) {
	if (n == root) {
		n->red = false;
		return;
	}

	if (n->parent->red) {
		Node* uncle;

		if (n->value < n->parent->parent->value) {
			// n is to the left of grandparent
			uncle = n->parent->parent->right;
		}
		else {
			// n is to the right of grandparent
			uncle = n->parent->parent->left;
		}

		if (uncle == NULL || uncle->red == false) {

		}
		else {
			uncle->red = n->parent->red = false;
			n->parent->parent->red = true;
			restoreTreeInvariant(n->parent->parent);
		}
	}
}


void RedBlackTree::rotateRight(Node* n) {

}
void RedBlackTree::rotateLeft(Node* n);

void RedBlackTree::leftleftCase(Node* n);
void RedBlackTree::leftRightCase(Node* n);
void RedBlackTree::rightLeftCase(Node* n);
void RedBlackTree::rightRightCase(Node* n);
