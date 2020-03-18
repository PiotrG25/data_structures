
#include "Doubly Linked List.h"

DoublyLinkedList::Node::Node(int element) {
	this->value = element;
	this->left = NULL;
	this->right = NULL;
}

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
	if (size == 0) {
		head = tail = new Node(element);
	}
	else {
		head->left = new Node(element);
		head->left->right = head;
		head = head->left;
	}

	++size;
}

void DoublyLinkedList::addLast(int element) {
	if (size == 0) {
		head = tail = new Node(element);
	}
	else {
		tail->right = new Node(element);
		tail->right->left = tail;
		tail = tail->right;
	}

	++size;
}

void DoublyLinkedList::addAt(int element, int index) {
	if (index <= 0) {
		addFirst(element);
		return;
	}
	else if (index >= size) {
		addLast(element);
		return;
	}

	if (size == 0) {
		head = tail = new Node(element);
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
	if (size == 0) return;
	if (head->right == NULL) {
		delete head;
		head = tail = NULL;
	}
	else {
		head = head->right;
		delete head->left;
		head->left = NULL;
	}

	--size;
}

void DoublyLinkedList::removeLast() {
	if (size == 0);
	if (tail->left == NULL) {
		delete tail;
		head = tail = NULL;
	}
	else {
		tail = tail->left;
		delete tail->right;
		tail->right = NULL;
	}

	--size;
}

void DoublyLinkedList::removeAt(int index) {
	if (index < 0 || index >= size) return;

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
	int i = find(element);
	if (i < 0) return;
	removeAt(i);
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
	return -1;
}

int DoublyLinkedList::getSize() {
	return size;
}

void DoublyLinkedList::print() {
	Node* n = head;
	std::cout << '[';
	for (int i = 0; i < size - 1; ++i, n = n->right) std::cout << n->value << ' ';
	if (size > 0) std::cout << n->value;

	std::cout << ']';
	std::cout << std::endl;
	std::cout << '[';

	for (int i = 0; i < size - 1; ++i, n = n->left) std::cout << n->value << ' ';
	if (size > 0) std::cout << n->value;

	std::cout << ']';
	std::cout << std::endl;
}


