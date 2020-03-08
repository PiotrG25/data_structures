
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
	if (root != NULL) deleteNode(root);
}

void RedBlackTree::deleteNode(Node* n) {
	if (n->left != NULL) deleteNode(n->left);
	if (n->right != NULL) deleteNode(n->right);
	delete n;
}


void RedBlackTree::remove(int element) {

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

			Node* grandgrandparent = n->parent->parent->parent, *result;

			if (n->value < n->parent->parent->value) {
				if (n->value < n->parent->value) {
					result = leftleftCase(n);
				}
				else {
					result = leftRightCase(n);
				}
			}
			else {
				if (n->value < n->parent->value) {
					result = rightLeftCase(n);
				}
				else {
					result = rightRightCase(n);
				}
			}


			if (grandgrandparent == NULL) {
				root = result;
				result->parent = NULL;
			}
			else {
				if (result->value < grandgrandparent->value) {
					grandgrandparent->left = result;
					result->parent = grandgrandparent;
				}
				else {
					grandgrandparent->right = result;
					result->parent = grandgrandparent;
				}
			}

			restoreTreeInvariant(result);
		}
		else {
			uncle->red = n->parent->red = false;
			n->parent->parent->red = true;
			restoreTreeInvariant(n->parent->parent);
		}
	}
}


void RedBlackTree::rotateRight(Node* n) {
	Node* parent = n->parent;

	parent->left = n->right;
	if (n->right != NULL) n->right->parent = parent;

	n->right = parent;
	parent->parent = n;
}
void RedBlackTree::rotateLeft(Node* n) {
	Node* parent = n->parent;

	parent->right = n->left;
	if (n->left != NULL) n->left->parent = parent;

	n->left = parent;
	parent->parent = n;
}

RedBlackTree::Node* RedBlackTree::leftleftCase(Node* n) {
	rotateRight(n->parent);

	bool t = n->parent->red;
	n->parent->red = n->parent->right->red;
	n->parent->right->red = t;

	return n->parent;
}
RedBlackTree::Node* RedBlackTree::leftRightCase(Node* n) {
	Node* grandparent = n->parent->parent;
	rotateLeft(n);

	n->parent = grandparent;
	grandparent->left = n;

	rotateRight(n);

	bool t = n->red;
	n->red = n->right->red;
	n->right->red = t;

	return n;
}
RedBlackTree::Node* RedBlackTree::rightLeftCase(Node* n) {
	Node* grandparent = n->parent->parent;
	rotateRight(n);

	n->parent = grandparent;
	grandparent->right = n;

	rotateLeft(n);

	bool t = n->red;
	n->red = n->left->red;
	n->left->red = t;

	return n;
}
RedBlackTree::Node* RedBlackTree::rightRightCase(Node* n) {
	rotateLeft(n->parent);

	bool t = n->parent->red;
	n->parent->red = n->parent->left->red;
	n->parent->left->red = t;

	return n->parent;
}


void RedBlackTree::print() {
	if (root == NULL) std::cout << "NULL" << std::endl;
	else printNode(root);
}

void RedBlackTree::printNode(Node* n) {
	std::cout << n->value << ' ';
	if (n->red) std::cout << 'R' << ' ';
	else std::cout << 'B' << ' ';

	if (n->parent == NULL) std::cout << "NULL" << ' ';
	else std::cout << n->parent->value << ' ';

	if (n->left == NULL) std::cout << "NULL" << ' ';
	else std::cout << n->left->value << ' ';

	if (n->right == NULL) std::cout << "NULL" << std::endl;
	else std::cout << n->right->value << std::endl;


	if (n->left != NULL) printNode(n->left);
	if (n->right != NULL) printNode(n->right);
}

