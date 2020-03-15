
#include "Binary Heap.h"


BinaryHeap::BinaryHeap(int* arr, int size) {

	// array without resizing requires more space
	length = 2 * size + 100;
	this->arr = new int[length];

	this->size = size;
	for (int i = 0; i < size; ++i) this->arr[i] = arr[i];

	// starting from node holding the last leaf
	// we are restoring heap invariant 
	// according to Floyd's algorithm O(n)
	for (int i = getParentIndex(size - 1); i >= 0; --i) bubbleDown(i);
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

	if (index >= size) return;

	arr[index] = arr[--size];
	bubbleDown(index);
}

bool BinaryHeap::search(int element) {
	for (int i = 0; i < size; ++i) if (arr[i] == element) return true;
	return false;
}


void BinaryHeap::bubbleUp(int index) {
	if (index <= 0) return;

	int parent = getParentIndex(index);
	while (arr[parent] < arr[index]) {
		int t = arr[parent];
		arr[parent] = arr[index];
		arr[index] = t;

		index = parent;
		parent = getParentIndex(index);
	}
}

void BinaryHeap::bubbleDown(int index) {
	int left = getLeftChildIndex(index), right = getRightChildIndex(index);

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

			left = getLeftChildIndex(index);
			right = getRightChildIndex(index);
		}
	}
}


int BinaryHeap::getParentIndex(int index) {
	return (index - 1) / 2;
}

int BinaryHeap::getLeftChildIndex(int index) {
	return index * 2 + 1;
}

int BinaryHeap::getRightChildIndex(int index) {
	return index * 2 + 2;
}


int BinaryHeap::getSize() {
	return size;
}


void BinaryHeap::print() {
	for (int i = 1; i < size; ++i) std::cout << arr[i - 1] << ' ';
	std::cout << arr[size - 1] << std::endl;
}

