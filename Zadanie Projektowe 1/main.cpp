
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
	/*
	int samples;
	cin >> samples;

	for (int i = 1;; i <<= 1) {
		testRedBlackTree(i, samples);
	}*/

	int n = 10;
	int* arr = makeRandomArray(n);
	AVLTree* tree = new AVLTree(arr, n);
	tree->print();

	int a, b;
	do {
		cin >> a >> b;
		cout << endl;

		if (a == 1) tree->add(b);
		else if (a == 2) tree->remove(b);

		tree->print();
	} while (a != 0);

	return 0;
}


