
#include "Binary Heap.h"


BinaryHeap::BinaryHeap(int* arr, int size) {

	// array without resizing requires more space
	this->length = 2 * size + 100;

	this->size = size;
	this->arr = new int[this->length];
	for (int i = 0; i < size; ++i) this->arr[i] = arr[i];

	// starting from node holding the last leaf
	// we are restoring heap invariant 
	// according to Floyd's algorithm
	for (int i = getParent(size - 1); i >= 0; --i) bubbleDown(i);
}

BinaryHeap::~BinaryHeap() {
	delete[] arr;
}


void BinaryHeap::add(int element) {
	if (size >= length) throw OUT_OF_SPACE;

	arr[size] = element;
	bubbleUp(size++);
}

void BinaryHeap::remove(int element) {
	int index = 0;
	for (; index < size && arr[index] != element; ++index);

	if (index >= size) throw NOT_FOUND;

	arr[index] = arr[--size];
	bubbleDown(index);
}

bool BinaryHeap::search(int element) {
	for (int i = 0; i < size; ++i) if (arr[i] == element) return true;
	return false;
}


void BinaryHeap::bubbleUp(int index) {
	int parent = getParent(index);
	
	while (index > 0 && arr[parent] < arr[index]) {
		int t = arr[parent];
		arr[parent] = arr[index];
		arr[index] = t;

		index = parent;
		parent = getParent(index);
	}
}

void BinaryHeap::bubbleDown(int index) {
	int left = getLeftChild(index), right = getRightChild(index);

	while (true) {
		if (left >= size) {
			// node has no children
			break;
		}
		else if (right >= size) {
			// node has only one child

			if (arr[left] > arr[index]) {
				int t = arr[left];
				arr[left] = arr[index];
				arr[index] = t;
			}

			break;
		}
		else {
			// node has two children

			if (arr[left] > arr[right]) {
				if (arr[left] > arr[index]) {
					int t = arr[left];
					arr[left] = arr[index];
					arr[index] = t;

					index = left;
				}
				else break;
			}
			else {
				if (arr[right] > arr[index]) {
					int t = arr[right];
					arr[right] = arr[index];
					arr[index] = t;

					index = right;
				}
				else break;
			}

			left = getLeftChild(index);
			right = getRightChild(index);
		}
	}
}

int BinaryHeap::getParent(int index) {
	return (index - 1) / 2;
}

int BinaryHeap::getLeftChild(int index) {
	return index * 2 + 1;
}

int BinaryHeap::getRightChild(int index) {
	return index * 2 + 2;
}

int BinaryHeap::getSize() {
	return size;
}

int BinaryHeap::peek() {
	if (size <= 0) throw EMPTY;
	return arr[0];
}


void BinaryHeap::print() {
	int depth = 0, s = size;
	while (s > 0) {
		++depth;
		s /= 2;
	}

	int NUMBER_WIDTH = 3;

	int width = NUMBER_WIDTH * (int)pow(2, depth);
	int i = 0;

	for (int j = 1; j <= depth; ++j) {
		for (int k = 0; i < size && k < (int)pow(2, j - 1); ++k, ++i) {
			for (int m = 0; m < width / 2 - NUMBER_WIDTH / 2; ++m) std::cout << ' ';
			std::cout << std::setw(NUMBER_WIDTH) << arr[i];
			for (int m = 0; m < width / 2 - NUMBER_WIDTH / 2 - 1; ++m) std::cout << ' ';
		}
		std::cout << std::endl;
		width /= 2;
		if (i >= size) break;
	}

}

