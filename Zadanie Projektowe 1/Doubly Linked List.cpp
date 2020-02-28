
#include "Doubly Linked List.h"

DoublyLinkedList::DoublyLinkedList(int* arr, int size) {
		this->size = size;
	if (size == 0) {
		head = NULL;
		tail = NULL;
	}
	else {
		head = new Node(arr[0]);
		Node* n = tail = head;
		for (int i = 1; i < size; ++i) {
			tail = new Node(arr[i]);
			n->right = tail;
			tail->left = n;
			n = tail;
		}
	}
}


void DoublyLinkedList::addFirst(int element) {
	addAt(element, 0);
}

void DoublyLinkedList::addLast(int element) {
	addAt(element, size);
}

void DoublyLinkedList::addAt(int element, int index) {
	if (index < 0 || index > size) throw OUT_OF_BOUND;

	if (size == 0) {
		head = tail = new Node(element);
	}
	else if (index == 0) {
		head->left = new Node(element);
		head->left->right = head;
		head = head->left;
	}
	else if (index == size) {
		tail->right = new Node(element);
		tail->right->left = tail;
		tail = tail->right;
	}
	else {
		Node* n = head;
		for (int i = 0; i < index; ++i) n = n->right;

		n->left->right = new Node(element);
		n->left->right->right = n;
		n->left->right->left = n->left;
		n->left = n->left->right;
	}

	++size;
}


void DoublyLinkedList::removeFirst() {
	removeAt(0);
}

void DoublyLinkedList::removeLast() {
	removeAt(size - 1);
}

void DoublyLinkedList::removeAt(int index) {
	if (size == 0) throw EMPTY;
	if (index < 0 || index >= size) throw OUT_OF_BOUND;

	Node* n = head;
	for (int i = 0; i < index; ++i) n = n->right;

	if (n->left == NULL) {
		if (n->right == NULL) {
			delete n;
			head = tail = NULL;
		}
		else {
			head = head->right;
			head->left = NULL;
			delete n;
		}
	}
	else {
		if (n->right == NULL) {
			tail = tail->left;
			tail->right = NULL;
			delete n;
		}
		else {
			n->left->right = n->right;
			n->right->left = n->left;
			delete n;
		}
	}
	
	--size;
}

void DoublyLinkedList::remove(int element){
	removeAt(find(element));
}


bool DoublyLinkedList::search(int element) {
	Node* n = head;
	for (int i = 0; i < size; ++i) {
		if (n->value == element) return true;
		n = n->right;
	}
	return false;
}

int DoublyLinkedList::find(int element) {
	Node* n = head;
	for (int i = 0; i < size; ++i, n = n->right) if (n->value == element) return i;
	throw NOT_FOUND;
}

int DoublyLinkedList::getSize() {
	return size;
}

void DoublyLinkedList::print() {
	Node* n = head;

	for (int i = 0; i < size - 1; ++i, n = n->right) std::cout << n->value << ' ';
	if (size > 0) std::cout << n->value;

	std::cout << std::endl;

	for (int i = 0; i < size - 1; ++i, n = n->left) std::cout << n->value << ' ';
	if (size > 0) std::cout << n->value;

	std::cout << std::endl;
}


