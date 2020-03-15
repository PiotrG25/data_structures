
#include "Red Black Tree.h"


// PUBLIC ----------------------------------------------------------------------------------------

RedBlackTree::RedBlackTree(int* arr, int size) {
	this->size = 0;
	root = NULL;
	for (int i = 0; i < size; ++i) add(arr[i]);
}

RedBlackTree::~RedBlackTree() {
	if (root != NULL) deleteSubtree(root);
}


void RedBlackTree::add(int element) {

	if (size == 0) {
		root = new Node(element, false); // new black Node
		++size;
		return;
	}

	Node* n = root;
	while (n != NULL) {
		if (element == n->value) return;
		else if (element < n->value) {
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

void RedBlackTree::remove(int element) {
	if (size == 0) return; // tree is empty

	Node* n = root;
	while (n != NULL) {
		if (n->value == element) break;
		if (element < n->value) n = n->left;
		else if (element > n->value) n = n->right;
	}

	if (n == NULL) return; // element is not in the tree

	if (n->left == NULL && n->right == NULL) removeLeaf(n);
	else if (n->left == NULL) removeNodeWithRightSubtree(n);
	else if (n->right == NULL) removeNodeWithLeftSubtree(n);
	else removeNodeWithBothSubtrees(n);

	--size;
}

bool RedBlackTree::search(int element) {
	Node* n = root;
	while (n != NULL) {
		if (element < n->value) n = n->left;
		else if(element > n->value) n = n->right;
		else return true;
	}
	return false;
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


bool RedBlackTree::isCorrectTree() {
	if (root == NULL) return true;
	else {
		if (root->red) return false;
		int l = 0, r = 0;

		if (root->left != NULL)
			if (!isCorrectSubtree(root->left, l)) return false;
		if (root->right != NULL)
			if (!isCorrectSubtree(root->right, r)) return false;

		return l == r;
	}
}


// PRIVATE ----------------------------------------------------------------------------------------


RedBlackTree::Node::Node(int value, bool red) {
	this->value = value;
	this->red = red;
	left = right = parent = NULL;
}

void RedBlackTree::deleteSubtree(Node* n) {
	if (n != NULL) {
		if (n->left != NULL) deleteSubtree(n->left);
		if (n->right != NULL) deleteSubtree(n->right);
		delete n;
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


void RedBlackTree::givenRedRestoreTreeInvariant(Node* n) {
	if (n == root) {
		n->red = false;
		return;
	}

	if (!n->parent->red) return;


	// getting parent, grandparent and uncle
	Node* parent = n->parent, * grandparent = parent->parent, * uncle;
	if (n->value < grandparent->value) uncle = grandparent->right;
	else uncle = grandparent->left;


	// because parent is red action depends on uncle
	if (uncle == NULL || uncle->red == false) {
		Node* greatgrandparent = grandparent->parent, * result;


		// deciding in which case is n
		if (n->value < grandparent->value) {
			if (n->value < n->parent->value) result = redRedLeftleftCase(n);
			else result = redRedLeftRightCase(n);
		}
		else {
			if (n->value < n->parent->value) result = redRedRightLeftCase(n);
			else result = redRedRightRightCase(n);
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


RedBlackTree::Node* RedBlackTree::redRedLeftleftCase(Node* n) {
	rotateRight(n->parent);

	bool t = n->parent->red;
	n->parent->red = n->parent->right->red;
	n->parent->right->red = t;

	return n->parent;
}

RedBlackTree::Node* RedBlackTree::redRedLeftRightCase(Node* n) {
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

RedBlackTree::Node* RedBlackTree::redRedRightLeftCase(Node* n) {
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

RedBlackTree::Node* RedBlackTree::redRedRightRightCase(Node* n) {
	rotateLeft(n->parent);

	bool t = n->parent->red;
	n->parent->red = n->parent->left->red;
	n->parent->left->red = t;

	return n->parent;
}


void RedBlackTree::givenDoubleBlackRestoreTreeInvariant(Node* n) {
	if (n == root) return;

	// parent, sibling, left nephew, right nephew, grandparent
	Node* p = n->parent, * s, * ln, * rn, * g = p->parent;
	if (n->value < p->value) {
		s = p->right;
		ln = s->left;
		rn = s->right;

		if (s->red) {
			p->red = true;
			s->red = false;
			rotateLeft(s);

			connectTopOfSubtreeToHigherNode(s, g);

			givenDoubleBlackRestoreTreeInvariant(n);
		}
		else {
			if (rn->red) {
				// right right case
				rn->red = s->red;
				s->red = p->red;
				p->red = false;
				rotateLeft(s);

				connectTopOfSubtreeToHigherNode(s, g);
			}
			else if (ln->red) {
				// right left case
				ln->red = p->red;
				p->red = false;

				rotateRight(ln);
				ln->parent = p;
				p->right = ln;
				rotateLeft(ln);

				connectTopOfSubtreeToHigherNode(ln, g);
			}
			else {
				s->red = true;
				if (p->red) p->red = false;
				else givenDoubleBlackRestoreTreeInvariant(p);
			}
		}
	}
	else {
		s = p->left;
		ln = s->left;
		rn = s->right;

		if (s->red) {
			p->red = false;
			s->red = true;
			rotateRight(s);

			connectTopOfSubtreeToHigherNode(s, g);

			givenDoubleBlackRestoreTreeInvariant(n);
		}
		else {
			if (ln->red) {
				// left left case
				ln->red = s->red;
				s->red = p->red;
				p->red = false;
				rotateRight(s);

				connectTopOfSubtreeToHigherNode(s, g);
			}
			else if (rn->red) {
				// left right case
				rn->red = p->red;
				p->red = false;
				rotateLeft(rn);
				rn->parent = p;
				p->left = rn;
				rotateRight(rn);

				connectTopOfSubtreeToHigherNode(rn, g);
			}
			else {
				s->red = true;
				if (p->red) p->red = false;
				else givenDoubleBlackRestoreTreeInvariant(p);
			}
		}
	}


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

	// 1 1 1 2 1 3 1 4 1 5 1 6
	// n is black
	// decide by parent, sibling and nephews
	Node* p = n->parent, * s;
	if (n->value <= p->value) {
		s = p->right;
		if (s->red) removeBlackLeafWithRedSiblingLeftCase(n);
		else {
			if (s->right != NULL && s->right->red) removeBlackLeafWithBlackSiblingRedNephewRightRightCase(n);
			else if (s->left != NULL && s->left->red) removeBlackLeafWithBlackSiblingRedNephewRightLeftCase(n);
			else removeBlackLeafWithBlackSiblingBlackNephewsLeftCase(n);
		}
	}
	else {
		s = p->left;
		if (s->red) removeBlackLeafWithRedSiblingRightCase(n);
		else {
			if (s->left != NULL && s->left->red) removeBlackLeafWithBlackSiblingRedNephewLeftLeftCase(n);
			else if (s->right != NULL && s->right->red) removeBlackLeafWithBlackSiblingRedNephewLeftRightCase(n);
			else removeBlackLeafWithBlackSiblingBlackNephewsRightCase(n);
		}
	}
}

void RedBlackTree::removeNodeWithRightSubtree(Node* n) {
	// the only possibility is that n is BLACK and its child is RED

	if (n == root) {
		root = n->right;
		root->parent = NULL;
		root->red = false;

		delete n;
		return;
	}

	if (n->value < n->parent->value) n->parent->left = n->right;
	else n->parent->right = n->right;

	n->right->parent = n->parent;
	n->right->red = false;

	delete n;
}

void RedBlackTree::removeNodeWithLeftSubtree(Node* n) {
	// the only possibility is that n is BLACK and its child is RED

	if (n == root) {
		root = n->left;
		root->parent = NULL;
		root->red = false;

		delete n;
		return;
	}

	if (n->value < n->parent->value) n->parent->left = n->left;
	else n->parent->right = n->left;

	n->left->parent = n->parent;
	n->left->red = false;

	delete n;
}

void RedBlackTree::removeNodeWithBothSubtrees(Node* n) {
	Node* m = n->left;
	while (m->right != NULL) m = m->right;

	n->value = m->value;

	if (m->left != NULL) removeNodeWithLeftSubtree(m);
	else removeLeaf(m);
}


void RedBlackTree::removeBlackLeafWithBlackSiblingRedNephewLeftLeftCase(Node* n) {
	// parent, sibling, red nephew, grandparent
	Node* p = n->parent, * s = p->left, * r = s->left, * g = p->parent;

	rotateRight(s);
	s->red = p->red;
	p->red = false;
	r->red = false;

	p->right = NULL;
	delete n;

	if (g == NULL) {
		root = s;
		s->parent = NULL;
	}
	else {
		if (s->value < g->value) g->left = s;
		else g->right = s;
		s->parent = g;
	}
}

void RedBlackTree::removeBlackLeafWithBlackSiblingRedNephewLeftRightCase(Node* n) {
	// parent, sibling, red nephew, grandparent
	Node* p = n->parent, * s = p->left, * r = s->right, * g = p->parent;

	rotateLeft(r);
	r->parent = p;
	p->left = r;
	rotateRight(r);

	r->red = p->red;
	p->red = false;

	p->right = NULL;
	delete n;

	if (g == NULL) {
		root = r;
		r->parent = NULL;
	}
	else {
		if (r->value < g->value) g->left = r;
		else g->right = r;
		r->parent = g;
	}
}

void RedBlackTree::removeBlackLeafWithBlackSiblingRedNephewRightLeftCase(Node* n) {
	// parent, sibling, red nephew, grandparent
	Node* p = n->parent, * s = p->right, * r = s->left, * g = p->parent;

	rotateRight(r);
	r->parent = p;
	p->right = r;
	rotateLeft(r);

	r->red = p->red;
	p->red = false;

	p->left = NULL;
	delete n;

	if (g == NULL) {
		root = r;
		r->parent = NULL;
	}
	else {
		if (r->value < g->value) g->left = r;
		else g->right = r;
		r->parent = g;
	}
}

void RedBlackTree::removeBlackLeafWithBlackSiblingRedNephewRightRightCase(Node* n) {
	// parent, sibling, red nephew, grandparent
	Node* p = n->parent, * s = p->right, * r = s->right, * g = p->parent;

	rotateLeft(s);
	s->red = p->red;
	p->red = false;
	r->red = false;

	p->left = NULL;
	delete n;

	if (g == NULL) {
		root = s;
		s->parent = NULL;
	}
	else {
		if (s->value < g->value) g->left = s;
		else g->right = s;
		s->parent = g;
	}
}


void RedBlackTree::removeBlackLeafWithBlackSiblingBlackNephewsLeftCase(Node* n) {
	// parent, sibling, grandparent
	Node* p = n->parent, * s = p->right, * g = p->parent;

	p->left = NULL;
	delete n;

	s->red = true;
	if (p->red) p->red = true;
	else givenDoubleBlackRestoreTreeInvariant(p);
}

void RedBlackTree::removeBlackLeafWithBlackSiblingBlackNephewsRightCase(Node* n) {
	// parent, sibling, grandparent
	Node* p = n->parent, * s = p->left, * g = p->parent;
	
	p->right = NULL;
	delete n;
	
	s->red = true;
	if (p->red) p->red = false;
	else givenDoubleBlackRestoreTreeInvariant(p);
}

void RedBlackTree::removeBlackLeafWithRedSiblingLeftCase(Node* n) {
	// parent, sibling, left nephew, grandparent
	Node* p = n->parent, * s = p->right, *ln = s->left, * g = p->parent;

	rotateLeft(s);
	s->red = p->red;
	p->red = false;
	ln->red = true;

	p->left = NULL;
	delete n;

	if (g == NULL) {
		root = s;
		s->parent = NULL;
	}
	else {
		if (s->value < g->value) g->left = s;
		else g->right = s;
		s->parent = g;
	}
}

void RedBlackTree::removeBlackLeafWithRedSiblingRightCase(Node* n) {
	// parent, sibling, right nephew, grandparent
	Node* p = n->parent, * s = p->left, * rn = s->right, * g = p->parent;

	rotateRight(s);
	s->red = p->red;
	p->red = false;
	rn->red = true;

	p->right = NULL;
	delete n;

	if (g == NULL) {
		root = s;
		s->parent = NULL;
	}
	else {
		if (s->value < g->value) g->left = s;
		else g->right = s;
		s->parent = g;
	}
}


void RedBlackTree::connectTopOfSubtreeToHigherNode(Node* top, Node* higher) {
	if (higher == NULL) {
		root = top;
		root->parent = NULL;
	}
	else {
		if (top->value < higher->value) higher->left = top;
		else higher->right = top;
		top->parent = higher;
	}
}


bool RedBlackTree::isCorrectSubtree(Node* n, int & height) {
	if (n->red && n->parent->red) return false;
	int l = 0, r = 0;

	if (n->left != NULL)
		if (!isCorrectSubtree(n->left, l)) return false;
	if (n->right != NULL)
		if (!isCorrectSubtree(n->right, r)) return false;

	if (l != r) return false;
	else {
		height = l;
		if (!n->red) height++;
		return true;
	}
}
