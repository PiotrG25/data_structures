
#include "AVL Tree.h"


AVLTree::Node::Node(int value) {
	this->value = value;
	left = right = NULL;
	balancedFactor = 0;
}


void AVLTree::deleteSubtree(Node* n) {
	if (n->left != NULL) deleteSubtree(n->left);
	if (n->right != NULL) deleteSubtree(n->right);
	delete n;
}


AVLTree::AVLTree(int* arr, int n) {
	root = NULL;
	size = 0;
	for (int i = 0; i < n; ++i) add(arr[i]);
}

AVLTree::~AVLTree() {
	if(root != NULL) deleteSubtree(root);
}


void AVLTree::add(int element) {

}

void AVLTree::remove(int element) {

}

bool AVLTree::search(int element) {

}




