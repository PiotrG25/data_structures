
#include <iostream>
#include <ctime>

#include "Array.h"
#include "Doubly Linked List.h"
#include "Binary Heap.h"

using namespace std;

int main() {

	cout << "Hello World" << endl;

	double t1, t2; // Zmienne do mierzenia czasu
	//cout << (t2 - t1) / (CLOCKS_PER_SEC) * 1000 << endl; // ms








	/*

	// list test


	int* arr = new int[10];
	for (int i = 0; i < 10; ++i) arr[i] = i + 1;

	DoublyLinkedList l = DoublyLinkedList(arr, 10);

	l.remove(8);
	cout << l.getSize() << endl;
	l.print();

	try {
		l.remove(8);
	}
	catch (const int e) {
		if (e == NOT_FOUND) {
			cout << "nie znaleziono elementu" << endl;
		}
	}

	cout << l.getSize() << endl;
	l.print();

	l.addFirst(123);
	cout << l.getSize() << endl;
	l.print();

	l.addLast(321);
	cout << l.getSize() << endl;
	l.print();

	l.addAt(44, 3);
	cout << l.getSize() << endl;
	l.print();


	l.removeFirst();
	cout << l.getSize() << endl;
	l.print();

	l.removeLast();
	cout << l.getSize() << endl;
	l.print();

	l.removeAt(5);
	cout << l.getSize() << endl;
	l.print();


	cout << l.search(123) << endl;
	cout << l.search(44) << endl;
	cout << l.search(666) << endl;


	cout << endl << endl << endl;

	try {
		l.removeAt(-1);
		cout << l.getSize() << endl;
		l.print();
	}
	catch (const int e) {
		if (e == OUT_OF_BOUND) {
			cout << "POZA GRANICAMI" << endl;
		}
		else if (e == EMPTY) {
			cout << "pusto" << endl;
		}
	}

	try {
		l.removeAt(444);
		cout << l.getSize() << endl;
		l.print();
	}
	catch (const int e) {
		if (e == OUT_OF_BOUND) {
			cout << "POZA GRANICAMI" << endl;
		}
		else if (e == EMPTY) {
			cout << "pusto" << endl;
		}
	}

	try {
		for (int i = 0; i <= 20; ++i) {
			l.removeAt(0);
			cout << l.getSize() << endl;
			l.print();
		}
	}
	catch (const int e) {
		if (e == OUT_OF_BOUND) {
			cout << "POZA GRANICAMI" << endl;
		}
		else if (e == EMPTY) {
			cout << "pusto" << endl;
		}
	}

	try {
		l.addAt(33, -1);
	}
	catch (const int e) {
		if (e == OUT_OF_BOUND) {
			cout << "POZA GRANICAMI" << endl;
		}
		else if (e == EMPTY) {
			cout << "pusto" << endl;
		}
	}

	try {
		l.addAt(11, 11);
	}
	catch (const int e) {
		if (e == OUT_OF_BOUND) {
			cout << "POZA GRANICAMI" << endl;
		}
		else if (e == EMPTY) {
			cout << "pusto" << endl;
		}
	}
	
	l.addFirst(44);
	cout << l.getSize() << endl;
	l.print();

	*/


	/*
	
	// Array TEST


	int* arr = new int[10];
	for (int i = 0; i < 10; ++i) arr[i] = i + 1;

	Array a = Array(arr, 10);

	a.addFirst(123);
	cout << a.getSize() << endl;
	a.print();

	a.addLast(321);
	cout << a.getSize() << endl;
	a.print();

	a.addAt(44, 3);
	cout << a.getSize() << endl;
	a.print();

	
	a.removeFirst();
	cout << a.getSize() << endl;
	a.print();

	a.removeLast();
	cout << a.getSize() << endl;
	a.print();

	a.removeAt(5);
	cout << a.getSize() << endl;
	a.print();
	

	try {
		for (int i = 0; i < 222; ++i) {
			a.removeFirst();
			cout << a.getSize() << endl;
			a.print();
		}
	}
	catch (const int e) {
		if (e == OUT_OF_BOUND) {
			cout << "POZA GRANICAMI" << endl;
		}
		else if (e == EMPTY) {
			cout << "pusto" << endl;
		}
	}

	a.addFirst(44);
	cout << a.getSize() << endl;
	a.print();

	try {
		a.removeAt(-1);
	}
	catch (const int e) {
		if (e == OUT_OF_BOUND) {
			cout << "POZA GRANICAMI" << endl;
		}
		else if (e == EMPTY) {
			cout << "pusto" << endl;
		}
	}

	try {
		a.removeAt(33);
	}
	catch (const int e) {
		if (e == OUT_OF_BOUND) {
			cout << "POZA GRANICAMI" << endl;
		}
		else if (e == EMPTY) {
			cout << "pusto" << endl;
		}
	}

	try {
		a.addAt(44, 555);
	}
	catch (const int e) {
		if (e == OUT_OF_BOUND) {
			cout << "POZA GRANICAMI" << endl;
		}
		else if (e == EMPTY) {
			cout << "pusto" << endl;
		}
	}

	try {
		a.addAt(44, -23);
	}
	catch (const int e) {
		if (e == OUT_OF_BOUND) {
			cout << "POZA GRANICAMI" << endl;
		}
		else if (e == EMPTY) {
			cout << "pusto" << endl;
		}
	}

	*/

	return 0;
}
