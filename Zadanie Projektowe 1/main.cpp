
#include <iostream>
#include <cstdlib>
#include <fstream>

#include "Array.h"
#include "Doubly Linked List.h"
#include "Binary Heap.h"
#include "Binary Search Tree.h"
#include "Red Black Tree.h"
#include "AVL Tree.h"

#include "Test.h"

using namespace std;


int main() {

	cout << "Hello World" << endl;

	int samples;
	cin >> samples;
	for (int i = 1;; i <<= 2) {
		testDoublyLinkedList(i, samples);
	}

	return 0;
}


