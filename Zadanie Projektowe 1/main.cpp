
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


int* readFromFile(int& n);

void useArray();
void useDoublyLinkedList();
void useBinaryHeap();
void useBinarySearchTree();
void useRedBlackTree();
void useAVLTree();


int main() {

	cout << "Hello World" << endl;
	/*
	int samples;
	cin >> samples;
	for (int i = 1;; i <<= 2) {
		testDoublyLinkedList(i, samples);
	}
	*/

	int a;
	string menu = "\
	\r[0] - zakoncz\n\
	\r[1] - Tablica dynamiczna\n\
	\r[2] - Lista dwukierunkowa\n\
	\r[3] - Binarny kopiec zupelny\n\
	\r[4] - Binarne drzewo poszukiwan\n\
	\r[5] - Drzewo czerwono czarne\n\
	\r[6] - Drzewno AVL\n\
	\r";

	while(true){
		cout << menu;
		cout << "wybor: ";
		cin >> a;

		if (a == 0) break;
		else if (a == 1) useArray();
		else if (a == 2) useDoublyLinkedList();
		else if (a == 3) useBinaryHeap();
		else if (a == 4) useBinarySearchTree();
		else if (a == 5) useRedBlackTree();
		else if (a == 6) useAVLTree();
		else cout << "wybor nie wspierany" << endl;
	}

	return 0;
}


int* readFromFile(int& n) {
	ifstream is;
	string name;
	cout << "Podaj nazwe pliku: ";
	cin >> name;

	is.open(name, ifstream::in);

	if (is.fail()) {
		cout << "Nie udalo sie otworzyc pliku" << endl;
		return NULL;
	}

	is >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; ++i) is >> arr[i];
	return arr;
}


void useArray() {
	Array* array = new Array(NULL, 0);
	string menu = "\
		\r[0] - powrot do menu glownego\n\
		\r[1] - wyswietl menu\n\
		\r[2] - wyswietl strukture danych\n\
		\r[3] - stworz strukture danych z pliku\n\
		\r[4] - dodaj na poczatku tablicy\n\
		\r[5] - dodaj na koncu tablicy\n\
		\r[6] - dodaj na wyznaczonym indeksie w tablicy\n\
		\r[7] - usun wartosc z tablicy\n\
		\r[8] - usun pierwszy element z tablicy\n\
		\r[9] - usun ostatni element z tablicy\n\
		\r[10] - usun element na wyznaczonym indeksie z tablicy\n\
		\r[11] - sprawdz czy element znajduje sie w tablicy\n\
		\r";
	cout << menu;


}

void useDoublyLinkedList() {
	DoublyLinkedList* list = new DoublyLinkedList(NULL, 0);
	string menu = "\
		\r[0] - powrot do menu glownego\n\
		\r[1] - wyswietl menu\n\
		\r[2] - wyswietl strukture danych\n\
		\r[3] - stworz strukture danych z pliku\n\
		\r[4] - dodaj na poczatku listy\n\
		\r[5] - dodaj na koncu listy\n\
		\r[6] - dodaj na wyznaczonym indeksie w liscie\n\
		\r[7] - usun wartosc z listy\n\
		\r[8] - usun pierwszy element z listy\n\
		\r[9] - usun ostatni element z listy\n\
		\r[10] - usun element na wyznaczonym indeksie z listy\n\
		\r[11] - sprawdz czy element znajduje sie w liscie\n\
		\r";
	cout << menu;


}

void useBinaryHeap() {
	BinaryHeap* heap = new BinaryHeap(NULL, 0);
	string menu = "\
		\r[0] - powrot do menu glownego\n\
		\r[1] - wyswietl menu\n\
		\r[2] - wyswietl strukture danych\n\
		\r[3] - stworz strukture danych z pliku\n\
		\r[4] - dodaj element do kopca\n\
		\r[5] - usun element z kopca\n\
		\r[6] - sprawdz czy element jest w kopcu\n\
		\r";
	cout << menu;


}

void useBinarySearchTree() {
	BinarySearchTree* binarySearchTree = new BinarySearchTree(NULL, 0);
	string menu = "\
		\r[0] - powrot do menu glownego\n\
		\r[1] - wyswietl menu\n\
		\r[2] - wyswietl strukture danych\n\
		\r[3] - stworz strukture danych z pliku\n\
		\r[4] - dodaj element do drzewa\n\
		\r[5] - usun element z drzewa\n\
		\r[6] - sprawdz czy element jest w drzewie\n\
		\r[7] - przywroc rownowage w drzewie\n\
		\r";
	cout << menu;


}

void useRedBlackTree() {
	RedBlackTree* redBlackTree = new RedBlackTree(NULL, 0);
	string menu = "\
		\r[0] - powrot do menu glownego\n\
		\r[1] - wyswietl menu\n\
		\r[2] - wyswietl strukture danych\n\
		\r[3] - stworz strukture danych z pliku\n\
		\r[4] - dodaj element do drzewa\n\
		\r[5] - usun element z drzewa\n\
		\r[6] - sprawdz czy element jest w drzewie\n\
		\r";
	cout << menu;


}

void useAVLTree() {
	AVLTree* avlTree = new AVLTree(NULL, 0);
	string menu = "\
		\r[0] - powrot do menu glownego\n\
		\r[1] - wyswietl menu\n\
		\r[2] - wyswietl strukture danych\n\
		\r[3] - stworz strukture danych z pliku\n\
		\r[4] - dodaj element do drzewa\n\
		\r[5] - usun element z drzewa\n\
		\r[6] - sprawdz czy element jest w drzewie\n\
		\r";

	cout << menu;


}

