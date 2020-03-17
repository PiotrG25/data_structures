
#include "AVL Tree.h"


AVLTree::Node::Node(int value) {
	this->value = value;
	left = right = NULL;
	balanceFactor = 0;
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
	if (root == NULL) root = new Node(element);
	else insert(root, NULL, element);
}

void AVLTree::remove(int element) {
	if (root != NULL) remove(root, NULL, element);
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


void AVLTree::remove(Node* n, Node* parent, int value) {
	if (value < n->value) remove(n->left, n, value);
	else if (value > n->value) remove(n->right, n, value);
	else {
		if (n->left == NULL && n->right == NULL) {
			if (parent == NULL) root = NULL;
			else {
				if (n->value < parent->value) parent->left = NULL;
				else parent->right = NULL;
			}

			delete n;
			--size;
		}
		else if (n->left == NULL) {
			if (parent == NULL) root = n->right;
			else {
				if (n->value < parent->value) parent->left = n->right;
				else parent->right = n->right;
			}

			delete n;
			--size;
		}
		else if (n->right == NULL) {
			if (parent == NULL) root = n->left;
			else {
				if (n->value < parent->value) parent->left = n->left;
				else parent->right = n->left;
			}

			delete n;
			--size;
		}
		else {
			Node* maxLeft = n->left;
			while (maxLeft->right != NULL) maxLeft = maxLeft->right;

			int t = maxLeft->value;
			remove(n->left, n, t);
			n->value = t;
		}
	}

	update(n);
	rebalance(n, parent);
}

void AVLTree::insert(Node* n, Node* parent, int value) {
	if (value < n->value) {
		if (n->left != NULL) insert(n->left, n, value);
		else {
			n->left = new Node(value);
			++size;
		}
	}
	else if (value > n->value) {
		if (n->right != NULL) insert(n->right, n, value);
		else {
			n->right = new Node(value);
			++size;
		}
	}
	else return;

	update(n);
	rebalance(n, parent);
}
void AVLTree::update(Node* n) {
	int leftHeight, rightHeight;

	if (n->left != NULL) leftHeight = n->left->height;
	else leftHeight = -1;

	if (n->right != NULL) rightHeight = n->right->height;
	else rightHeight = -1;

	if (leftHeight > rightHeight) n->height = leftHeight + 1;
	else n->height = rightHeight + 1;
	n->balanceFactor = rightHeight - leftHeight;
}
void AVLTree::rebalance(Node* n, Node* parent) {
	Node* top = NULL;

	if (n->balanceFactor == -2) {
		if (n->left->balanceFactor == -1) top = leftLeftCase(n);
		else top = leftRightCase(n);
	}
	else if (n->balanceFactor == 2) {
		if (n->right->balanceFactor == -1) top = rightLeftCase(n);
		else top = rightRightCase(n);
	}
	else return;

	if (top != NULL) {
		if (parent == NULL) {
			root = top;
		}
		else {
			if (top->value < parent->value) parent->left = top;
			else parent->right = top;
		}
	}
}

AVLTree::Node* AVLTree::rotateLeft(Node* n) {
	Node* r = n->right;
	n->right = r->left;
	r->left = n;

	return r;
}
AVLTree::Node* AVLTree::rotateRight(Node* n) {
	Node* l = n->left;
	n->left = l->right;
	l->right = n;

	return l;
}

AVLTree::Node* AVLTree::leftLeftCase(Node* n) {
	n = rotateRight(n);

	n->balanceFactor = n->left->balanceFactor = n->right->balanceFactor = 0;
	n->height = n->left->height + 1;
	n->right->height = n->left->height;

	return n;
}
AVLTree::Node* AVLTree::leftRightCase(Node* n) {
	n->left = rotateLeft(n->left);
	n = rotateRight(n);

	n->balanceFactor = n->left->balanceFactor = n->right->balanceFactor = 0;
	n->left->height = n->right->height = n->height;
	++n->height;

	return n;
}
AVLTree::Node* AVLTree::rightLeftCase(Node* n) {
	n->right = rotateRight(n->right);
	n = rotateLeft(n);

	n->balanceFactor = n->left->balanceFactor = n->right->balanceFactor = 0;
	n->left->height = n->right->height = n->height;
	++n->height;

	return n;
}
AVLTree::Node* AVLTree::rightRightCase(Node* n) {
	n = rotateLeft(n);

	n->balanceFactor = n->left->balanceFactor = n->right->balanceFactor = 0;
	n->height = n->right->height + 1;
	n->left->height = n->right->height;

	return n;
}
