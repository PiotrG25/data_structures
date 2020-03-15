
#include "Array.h"

Array::Array(int* arr, int size) {
	this->size = size;
	this->arr = new int[size];
	for (int i = 0; i < size; ++i) this->arr[i] = arr[i];
}

Array::~Array() {
	delete[] arr;
}


void Array::addFirst(int element) {
	addAt(element, 0);
}

void Array::addLast(int element) {
	addAt(element, size);
}

void Array::addAt(int element, int index) {
	if (index < 0) addFirst(element);
	if (index > size) addLast(element);


	int* newArr = new int[size + 1];
	
	for (int i = 0; i < index; ++i) newArr[i] = arr[i];
	newArr[index] = element;
	for (int i = index, j = index + 1; i < size; ++i, ++j) newArr[j] = arr[i];

	delete[] arr;
	arr = newArr;
	++size;
}


void Array::remove(int element) {
	int i = find(element);

	if (i < 0) return;
	else removeAt(i);
}

void Array::removeFirst() {
	removeAt(0);
}

void Array::removeLast() {
	removeAt(size - 1);
}

void Array::removeAt(int index) {
	if (index < 0 || index >= size) return;

	int* newArr = new int[size - 1];

	for (int i = 0; i < index; ++i) newArr[i] = arr[i];
	for (int i = index + 1, j = index; i < size; ++i, ++j) newArr[j] = arr[i];

	delete[] arr;
	arr = newArr;
	--size;
}


bool Array::search(int element) {
	for (int i = 0; i < size; ++i) if (arr[i] == element) return true;
	return false;
}

int Array::find(int element) {
	for (int i = 0; i < size; ++i) if (arr[i] == element) return i;
	return -1;
}

int Array::getSize() {
	return size;
}

void Array::print() {
	for (int i = 0; i < size - 1; ++i) std::cout << arr[i] << ' ';
	if (size > 0) std::cout << arr[size - 1];
	std::cout << std::endl;
}

