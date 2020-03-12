
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


void RedBlackTree::remove(int element) {
	if (size == 0) return; // todo exception

	Node* n = root;
	while (n != NULL) {
		if (n->value == element) break;
		if (element < n->value) n = n->left;
		else if (element > n->value) n = n->right;
	}

	if (n == NULL) return; // todo exception

	if (n->left == NULL && n->right == NULL) removeLeaf(n);
	else if (n->left == NULL) removeNodeWithRightSubtree(n);
	else if (n->right == NULL) removeNodeWithLeftSubtree(n);
	else removeNodeWithBothSubtrees(n);

	--size;
}

void RedBlackTree::removeLeaf(Node* n) {
	if (n == root) {
		root = NULL;
		delete n;
		return;
	}

	if (n->red) {
		if (n->value < n->parent->value) n->parent->left = NULL;
		else n->parent->right = NULL;

		delete n;
		return;
	}

	// n is black
	// decide by parent and sibling
	Node* parent = n->parent, * s;
	if (n->value < parent->value) {
		s = parent->right;
		if (s->red) removeBlackLeafWithRedSiblingLeftCase(n);
		else {
			if (s->right != NULL && s->right->red) removeBlackLeafWithBlackSiblingRedNephewRightRightCase(n);
			else if (s->left != NULL && s->left->red) removeBlackLeafWithBlackSiblingRedNephewRightLeftCase(n);
			else removeBlackLeafWithBlackSiblingBlackNephewsLeftCase(n);
		}
	}
	else {
		s = parent->left;
		if (s->red) removeBlackLeafWithRedSiblingRightCase(n);
		else {
			if (s->left != NULL && s->left->red) removeBlackLeafWithBlackSiblingRedNephewLeftLeftCase(n);
			else if (s->right != NULL && s->right->red) removeBlackLeafWithBlackSiblingRedNephewLeftRightCase(n);
			else removeBlackLeafWithBlackSiblingBlackNephewsRightCase(n);
		}
	}
}
void RedBlackTree::removeNodeWithRightSubtree(Node* n) {
	if (n == root) {
		root = n->right;
		root->parent = NULL;
		root->red = false;

		delete n;
		return;
	}

	if (n->red || n->right->red) {
		if (n->value < n->parent->value) n->parent->left = n->right;
		else n->parent->right = n->right;

		n->right->parent = n->parent;
		n->right->red = false;
		
		delete n;
		return;
	}

	// n and its child are black
	// decide by parent and sibling
	Node* parent = n->parent, * s;
	if (n->value < parent->value) {
		s = parent->right;
		if (s->red) removeBlackNodeWithRightSubtreeRedSiblingLeftCase(n);
		else {
			if (s->right != NULL && s->right->red) removeBlackNodeWithRightSubtreeBlackSiblingRedNephewRightRightCase(n);
			else if (s->left != NULL && s->left->red) removeBlackNodeWithRightSubtreeBlackSiblingRedNephewRightLeftCase(n);
			else removeBlackNodeWithRightSubtreeBlackSiblingBlackNephewsLeftCase(n);
		}
	}
	else {
		s = parent->left;
		if (s->red) removeBlackNodeWithRightSubtreeRedSiblingRightCase(n);
		else {
			if (s->left != NULL && s->left->red) removeBlackNodeWithRightSubtreeBlackSiblingRedNephewLeftLeftCase(n);
			else if (s->right != NULL && s->right->red) removeBlackNodeWithRightSubtreeBlackSiblingRedNephewLeftRightCase(n);
			else removeBlackNodeWithRightSubtreeBlackSiblingBlackNephewsRightCase(n);
		}
	}
}
void RedBlackTree::removeNodeWithLeftSubtree(Node* n) {
	if (n == root) {
		root = n->left;
		root->parent = NULL;
		root->red = false;

		delete n;
		return;
	}

	if (n->red || n->left->red) {
		if (n->value < n->parent->value) n->parent->left = n->left;
		else n->parent->right = n->left;

		n->left->parent = n->parent;
		n->left->red = false;
		
		delete n;
		return;
	}

	// n and its child are black
	// decide by parent and sibling
	Node* parent = n->parent, * s;
	if (n->value < parent->value) {
		s = parent->right;
		if (s->red) removeBlackNodeWithLeftSubtreeRedSiblingLeftCase(n);
		else {
			if (s->right != NULL && s->right->red) removeBlackNodeWithLeftSubtreeBlackSiblingRedNephewRightRightCase(n);
			else if (s->left != NULL && s->left->red) removeBlackNodeWithLeftSubtreeBlackSiblingRedNephewRightLeftCase(n);
			else removeBlackNodeWithLeftSubtreeBlackSiblingBlackNephewsLeftCase(n);
		}
	}
	else {
		s = parent->left;
		if (s->red) removeBlackNodeWithLeftSubtreeRedSiblingRightCase(n);
		else {
			if (s->left != NULL && s->left->red) removeBlackNodeWithLeftSubtreeBlackSiblingRedNephewLeftLeftCase(n);
			else if (s->right != NULL && s->right->red) removeBlackNodeWithLeftSubtreeBlackSiblingRedNephewLeftRightCase(n);
			else removeBlackNodeWithLeftSubtreeBlackSiblingBlackNephewsRightCase(n);
		}
	}
}
void RedBlackTree::removeNodeWithBothSubtrees(Node* n) {
	Node* m = n->left;
	while (m->right != NULL) m = m->right;

	int t = n->value;
	n->value = m->value;
	m->value = t;

	removeNodeWithLeftSubtree(m);
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
				n->left = new Node(element, true); // new red Node
				n->left->parent = n;
				n = n->left;
				break;
			}
			else n = n->left;
		}
		else {
			if (n->right == NULL) {
				n->right = new Node(element, true); // new red Node
				n->right->parent = n;
				n = n->right;
				break;
			}
			else n = n->right;
		}
	}
	++size;

	givenRedRestoreTreeInvariant(n);
}
void RedBlackTree::givenRedRestoreTreeInvariant(Node* n) {
	if (n == root) {
		n->red = false;
		return;
	}

	if (!n->parent->red) return;


	// getting parent, grandparent and uncle
	Node* parent = n->parent, *grandparent = parent->parent, * uncle;
	if (n->value < grandparent->value) uncle = grandparent->right;
	else uncle = grandparent->left;


	// because parent is red action depends on uncle
	if (uncle == NULL || uncle->red == false) {
		Node* greatgrandparent = grandparent->parent, *result;


		// deciding in which case is n
		if (n->value < grandparent->value) {
			if (n->value < n->parent->value) result = leftleftCase(n);
			else result = leftRightCase(n);
		}
		else {
			if (n->value < n->parent->value) result = rightLeftCase(n);
			else result = rightRightCase(n);
		}


		// connecting hihgest node to grandparent
		if (greatgrandparent == NULL) {
			root = result;
			result->parent = NULL;
		}
		else {
			if (result->value < greatgrandparent->value) greatgrandparent->left = result;
			else greatgrandparent->right = result;
			result->parent = greatgrandparent;
		}
	}
	else {
		uncle->red = parent->red = false;
		grandparent->red = true;
		givenRedRestoreTreeInvariant(grandparent);
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





void RedBlackTree::removeBlackLeafWithBlackSiblingRedNephewLeftLeftCase(Node* n);
void RedBlackTree::removeBlackLeafWithBlackSiblingRedNephewLeftRightCase(Node* n);
void RedBlackTree::removeBlackLeafWithBlackSiblingRedNephewRightLeftCase(Node* n);
void RedBlackTree::removeBlackLeafWithBlackSiblingRedNephewRightRightCase(Node* n);

void RedBlackTree::removeBlackLeafWithBlackSiblingBlackNephewsLeftCase(Node* n);
void RedBlackTree::removeBlackLeafWithBlackSiblingBlackNephewsRightCase(Node* n);

void RedBlackTree::removeBlackLeafWithRedSiblingLeftCase(Node* n) {
	Node* parent = n->parent, * s = parent->right, * grandparent = parent->parent;
	rotateLeft(s);

	s->red = false;
	parent->right->red = true;

	parent->left = NULL;

	if (grandparent == NULL) {
		root = s;
		s->parent = NULL;
	}
	else {
		if (s->value < grandparent->value) grandparent->left = s;
		else grandparent->right = s;
		s->parent = grandparent;
	}

	delete n;
}
void RedBlackTree::removeBlackLeafWithRedSiblingRightCase(Node* n) {
	Node* parent = n->parent, * s = parent->left, * grandparent = parent->parent;
	rotateRight(s);

	s->red = false;
	parent->left->red = true;

	parent->right = NULL;

	if (grandparent == NULL) {
		root = s;
		s->parent = NULL;
	}
	else {
		if (s->value < grandparent->value) grandparent->left = s;
		else grandparent->right = s;
		s->parent = grandparent;
	}

	delete n;
}


void RedBlackTree::removeBlackNodeWithLeftSubtreeBlackSiblingRedNephewLeftLeftCase(Node* n);
void RedBlackTree::removeBlackNodeWithLeftSubtreeBlackSiblingRedNephewLeftRightCase(Node* n);
void RedBlackTree::removeBlackNodeWithLeftSubtreeBlackSiblingRedNephewRightLeftCase(Node* n);
void RedBlackTree::removeBlackNodeWithLeftSubtreeBlackSiblingRedNephewRightRightCase(Node* n);

void RedBlackTree::removeBlackNodeWithLeftSubtreeBlackSiblingBlackNephewsLeftCase(Node* n);
void RedBlackTree::removeBlackNodeWithLeftSubtreeBlackSiblingBlackNephewsRightCase(Node* n);

void RedBlackTree::removeBlackNodeWithLeftSubtreeRedSiblingLeftCase(Node* n) {
	Node* parent = n->parent, * s = parent->right, * grandparent = parent->parent;
	rotateLeft(s);

	s->red = false;
	parent->right->red = true;

	parent->left = n->left;
	n->left->parent = parent;

	if (grandparent == NULL) {
		root = s;
		s->parent = NULL;
	}
	else {
		if (s->value < grandparent->value) grandparent->left = s;
		else grandparent->right = s;
		s->parent = grandparent;
	}

	delete n;
}
void RedBlackTree::removeBlackNodeWithLeftSubtreeRedSiblingRightCase(Node* n) {
	Node* parent = n->parent, * s = parent->left, * grandparent = parent->parent;
	rotateRight(s);

	s->red = false;
	parent->left->red = true;

	parent->right = n->left;
	n->left->parent = parent;

	if (grandparent == NULL) {
		root = s;
		s->parent = NULL;
	}
	else {
		if (s->value < grandparent->value) grandparent->left = s;
		else grandparent->right = s;
		s->parent = grandparent;
	}

	delete n;
}


void RedBlackTree::removeBlackNodeWithRightSubtreeBlackSiblingRedNephewLeftLeftCase(Node* n);
void RedBlackTree::removeBlackNodeWithRightSubtreeBlackSiblingRedNephewLeftRightCase(Node* n);
void RedBlackTree::removeBlackNodeWithRightSubtreeBlackSiblingRedNephewRightLeftCase(Node* n);
void RedBlackTree::removeBlackNodeWithRightSubtreeBlackSiblingRedNephewRightRightCase(Node* n);

void RedBlackTree::removeBlackNodeWithRightSubtreeBlackSiblingBlackNephewsLeftCase(Node* n);
void RedBlackTree::removeBlackNodeWithRightSubtreeBlackSiblingBlackNephewsRightCase(Node* n);

void RedBlackTree::removeBlackNodeWithRightSubtreeRedSiblingLeftCase(Node* n) {
	Node* parent = n->parent, * s = parent->right, * grandparent = parent->parent;
	rotateLeft(s);

	s->red = false;
	parent->right->red = true;

	parent->left = n->right;
	n->right->parent = parent;

	if (grandparent == NULL) {
		root = s;
		s->parent = NULL;
	}
	else {
		if (s->value < grandparent->value) grandparent->left = s;
		else grandparent->right = s;
		s->parent = grandparent;
	}

	delete n;
}
void RedBlackTree::removeBlackNodeWithRightSubtreeRedSiblingRightCase(Node* n) {
	Node* parent = n->parent, * s = parent->left, * grandparent = parent->parent;
	rotateRight(s);

	s->red = false;
	parent->left->red = true;

	parent->right = n->right;
	n->right->parent = parent;

	if (grandparent == NULL) {
		root = s;
		s->parent = NULL;
	}
	else {
		if (s->value < grandparent->value) grandparent->left = s;
		else grandparent->right = s;
		s->parent = grandparent;
	}

	delete n;
}