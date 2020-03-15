
#include "Binary Search Tree.h"


BinarySearchTree::Node::Node(int value) {
	this->value = value;
	left = right = NULL;
}

void BinarySearchTree::deleteSubtree(Node* n) {
	if (n != NULL) {
		if (n->left != NULL) deleteSubtree(n->left);
		if (n->right != NULL) deleteSubtree(n->right);
		delete n;
	}
}


BinarySearchTree::BinarySearchTree(int* arr, int size) {
	this->root = NULL;
	this->size = 0;
	for (int i = 0; i < size; ++i) add(arr[i]);
}

BinarySearchTree::~BinarySearchTree() {
	deleteSubtree(root);
}


void BinarySearchTree::add(int element) {
	if (size == 0) {
		root = new Node(element);
		++size;
		return;
	}

	Node* n = root;
	while (n != NULL) {
		if (element == n->value) return;
		else if (element < n->value) {
			if (n->left == NULL) {
				n->left = new Node(element);
				break;
			}
			else n = n->left;
		}
		else {
			if (n->right == NULL) {
				n->right = new Node(element);
				break;
			}
			else n = n->right;
		}
	}

	++size;
}

void BinarySearchTree::remove(int element) {
	if (size == 0) return; // tree is empty

	Node* n = root, * parent = NULL;
	while (n != NULL) {
		if (element == n->value) break;

		parent = n;

		if (element < n->value) n = n->left;
		else n = n->right;
	}

	if (n == NULL) return; // element is not in the tree


	if (n->left == NULL && n->right == NULL) removeLeaf(n, parent);
	else if (n->right == NULL) removeNodeWithLeftSubtree(n, parent);
	else if (n->left == NULL) removeNodeWithRightSubtree(n, parent);
	else {
		Node* maxLeft = n->left;
		while (maxLeft->right != NULL) maxLeft = maxLeft->right;
		
		int t = maxLeft->value;

		if (maxLeft->left != NULL) removeNodeWithLeftSubtree(maxLeft);
		else removeLeaf(maxLeft);

		n->value = t;
	}

	--size;
}


void BinarySearchTree::removeLeaf(Node* n, Node* parent) {
	if (parent == NULL) {
		delete n;
		root = NULL;
	}
	else if (n->value < parent->value) {
		parent->left = NULL;
		delete n;
	}
	else {
		parent->right = NULL;
		delete n;
	}
}

void BinarySearchTree::removeNodeWithLeftSubtree(Node* n, Node* parent) {
	if (parent == NULL) {
		root = root->left;
		delete n;
	}
	else if (n->value < parent->value) {
		parent->left = n->left;
		delete n;
	}
	else {
		parent->right = n->left;
		delete n;
	}
}

void BinarySearchTree::removeNodeWithRightSubtree(Node* n, Node* parent) {
	if (parent == NULL) {
		root = root->right;
		delete n;
	}
	else if (n->value < parent->value) {
		parent->left = n->right;
		delete n;
	}
	else {
		parent->right = n->right;
		delete n;
	}
}

bool BinarySearchTree::search(int element) {
	Node* n = root;
	while (n != NULL) {
		if (element < n->value) n = n->left;
		else if (element > n->value) n = n->right;
		else return true;
	}
	return false;
}


void BinarySearchTree::print() {
	if (root == NULL) std::cout << "NULL" << std::endl;
	else printNode(root);
}

void BinarySearchTree::printNode(Node* n) {
	if (n != NULL) {
		std::cout << n->value << ' ';
		
		if (n->left == NULL) std::cout << "NULL";
		else std::cout << n->left->value;
		std::cout << ' ';

		if (n->right == NULL) std::cout << "NULL";
		else std::cout << n->right->value;
		std::cout << std::endl;

		if (n->left != NULL) printNode(n->left);
		if (n->right != NULL) printNode(n->right);
	}
}


