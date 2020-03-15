
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
		parent = n;
		while (maxLeft->right != NULL) {
			parent = maxLeft;
			maxLeft = maxLeft->right;
		}
		
		int t = maxLeft->value;

		if (maxLeft->left != NULL) removeNodeWithLeftSubtree(maxLeft, parent);
		else removeLeaf(maxLeft, parent);

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


void BinarySearchTree::rebalanceTree() {
	if (root == NULL) return;

	Node* n = root, * parent = NULL;
	do {
		while (n->left != NULL) {
			n = rotateRight(n, parent);
		}
		parent = n;
		n = n->right;
	} while (n != NULL);

	int m = size / 2;
	if (m * 2 == size) --m;

	while (m > 0) {
		n = root;
		parent = NULL;
		for (int i = 0; i < m; ++i) {
			n = rotateLeft(n, parent);
			parent = n;
			n = n->right;
		}
		m /= 2;
	}
}


BinarySearchTree::Node* BinarySearchTree::rotateRight(Node* n, Node* parent) {
	Node* l = n->left;
	n->left = l->right;
	l->right = n;

	if (parent == NULL) {
		root = l;
	}
	else {
		if (l->value < parent->value) parent->left = l;
		else parent->right = l;
	}
	return l;
}
BinarySearchTree::Node* BinarySearchTree::rotateLeft(Node* n, Node* parent) {
	Node* r = n->right;
	n->right = r->left;
	r->left = n;

	if (parent == NULL) {
		root = r;
	}
	else {
		if (r->value < parent->value) parent->left = r;
		else parent->right = r;
	}
	return r;
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


