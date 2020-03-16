
#include "AVL Tree.h"


AVLTree::Node::Node(int value) {
	this->value = value;
	left = right = NULL;
	balancedFactor = 0;
	height = 0;
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
	Node* n = root;

	while (n != NULL) {
		if (element < n->value) n = n->left;
		else if (element > n->value) n = n->right;
		else return true;
	}

	return false;
}



void AVLTree::insert(Node* n, int value) {

}
void AVLTree::updane(Node* n) {

}
void AVLTree::rebalance(Node* n) {

}

AVLTree::Node* AVLTree::rotateLeft(Node* n) {

}
AVLTree::Node* AVLTree::rotateRight(Node* n) {

}

AVLTree::Node* AVLTree::leftLeftCase(Node* n) {

}
AVLTree::Node* AVLTree::leftRightCase(Node* n) {

}
AVLTree::Node* AVLTree::rightLeftCase(Node* n) {

}
AVLTree::Node* AVLTree::rightRightCase(Node* n) {

}
