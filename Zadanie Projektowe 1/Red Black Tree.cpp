
#include "Red Black Tree.h"

RedBlackTree::RedBlackTree(int * arr, int size) {
	this->size = 0;
	for (int i = 0; i < size; ++i) add(arr[i]);
}

RedBlackTree::~RedBlackTree() {

}


void RedBlackTree::add(int element) {
	Node* n = new Node(element, true); // new red node

	if (size == 0) {
		root = n;
		root->red = false;
		return;
	}


}
