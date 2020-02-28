
#include "Binary Heap.h"


BinaryHeap::BinaryHeap(int* arr, int size) {
	this->length = 2 * size + 100;
	this->size = 0;
	this->arr = new int[this->length];
	
	for (int i = 0; i < size; ++i) add(arr[i]);
}


void BinaryHeap::add(int element) {

	if (size >= length) throw OUT_OF_SPACE;

	arr[size++] = element;
	int index = size - 1;

	for (int parentIndex = getParent(index); index > 0 && arr[parentIndex] < arr[index];) {

		int t = arr[parentIndex];
		arr[parentIndex] = arr[index];
		arr[index] = t;

		index = parentIndex;
		parentIndex = getParent(index);
	}
}

void BinaryHeap::remove(int element) {
	int index = 0;
	for (; index < size; ++index) if (arr[index] == element) break;

	if (index >= size) throw NOT_FOUND;

	arr[index] = arr[--size];

	for (int left = getLeftChild(index), right = getRightChild(index);;) {
		if (left >= size && right >= size) break; // has no children
		else if (right >= size) { // has only left child
			if (arr[left] > arr[index]) {

				int t = arr[left];
				arr[left] = arr[index];
				arr[index] = t;
			}
			break;
		}
		else { // has both left and right child
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

bool BinaryHeap::search(int element) {
	for (int i = 0; i < size; ++i) if (arr[i] == element) return true;
	return false;
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


void BinaryHeap::print() {
	int depth = 0, s = size;
	while (s > 0) {
		++depth;
		s /= 2;
	}

	int NUMBER_WIDTH = 5;

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

