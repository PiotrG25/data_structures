
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
	int samples, interval, start, J;
	cin >> samples >> start >> interval >> J;
	for (int i = start, j = 0; j < J; i += interval) {
		testAVLTree(i, samples);
	}
	return 0;*/

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

	int a;
	while (true) {
		cout << "Tablica dynamiczna o rozmiarze: " << array->getSize() << endl;
		cout << "wybor: ";
		cin >> a;

		if (a == 0) break;
		else if (a == 1) {
			cout << menu;
		}
		else if (a == 2) {
			array->print();
		}
		else if (a == 3) {
			int n = 0;
			int* arr = readFromFile(n);
			delete array;
			array = new Array(arr, n);

			array->print();
		}
		else if (a == 4) {
			cout << "Podaj wartosc elementu: ";
			cin >> a;
			array->addFirst(a);

			array->print();
		}
		else if (a == 5) {
			cout << "Podaj wartosc elementu: ";
			cin >> a;
			array->addLast(a);

			array->print();
		}
		else if (a == 6) {
			cout << "Podaj wartosc elementu: ";
			cin >> a;
			int i;
			cout << "Podaj indeks: ";
			cin >> i;
			array->addAt(a, i);

			array->print();
		}
		else if (a == 7) {
			cout << "Podaj wartosc elementu: ";
			cin >> a;
			array->remove(a);

			array->print();
		}
		else if (a == 8) {
			array->removeFirst();

			array->print();
		}
		else if (a == 9) {
			array->removeLast();

			array->print();
		}
		else if (a == 10) {
			int i;
			cout << "Podaj indeks: ";
			cin >> i;
			array->removeAt(i);

			array->print();
		}
		else if (a == 11) {
			cout << "Podaj wartosc elementu: ";
			cin >> a;
			if (array->search(a)) cout << "Element znajduje sie w tablicy" << endl;
			else cout << "Element nie znajduje sie w tablicy" << endl;
		}
	}
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

	int a;
	while (true) {
		cout << "Lista dwukierunkowa o rozmiarze: " << list->getSize() << endl;
		cout << "wybor: ";
		cin >> a;

		if (a == 0) break;
		else if (a == 1) {
			cout << menu;
		}
		else if (a == 2) {
			cout << "Lista wyswietlana jest dwukrotnie" << endl;
			cout << "za pierwszym razem od poczatku do konca a za drugim od konca do poczatku" << endl;
			list->print();
		}
		else if (a == 3) {
			int n = 0;
			int* arr = readFromFile(n);
			delete list;
			list = new DoublyLinkedList(arr, n);

			cout << "Lista wyswietlana jest dwukrotnie" << endl;
			cout << "za pierwszym razem od poczatku do konca a za drugim od konca do poczatku" << endl;
			list->print();
		}
		else if (a == 4) {
			cout << "Podaj wartosc elementu: ";
			cin >> a;
			list->addFirst(a);

			cout << "Lista wyswietlana jest dwukrotnie" << endl;
			cout << "za pierwszym razem od poczatku do konca a za drugim od konca do poczatku" << endl;
			list->print();
		}
		else if (a == 5) {
			cout << "Podaj wartosc elementu: ";
			cin >> a;
			list->addLast(a);

			cout << "Lista wyswietlana jest dwukrotnie" << endl;
			cout << "za pierwszym razem od poczatku do konca a za drugim od konca do poczatku" << endl;
			list->print();
		}
		else if (a == 6) {
			cout << "Podaj wartosc elementu: ";
			cin >> a;
			int i;
			cout << "Podaj indeks: ";
			cin >> i;
			list->addAt(a, i);

			cout << "Lista wyswietlana jest dwukrotnie" << endl;
			cout << "za pierwszym razem od poczatku do konca a za drugim od konca do poczatku" << endl;
			list->print();
		}
		else if (a == 7) {
			cout << "Podaj wartosc elementu: ";
			cin >> a;
			list->remove(a);

			cout << "Lista wyswietlana jest dwukrotnie" << endl;
			cout << "za pierwszym razem od poczatku do konca a za drugim od konca do poczatku" << endl;
			list->print();
		}
		else if (a == 8) {
			list->removeFirst();

			cout << "Lista wyswietlana jest dwukrotnie" << endl;
			cout << "za pierwszym razem od poczatku do konca a za drugim od konca do poczatku" << endl;
			list->print();
		}
		else if (a == 9) {
			list->removeLast();

			cout << "Lista wyswietlana jest dwukrotnie" << endl;
			cout << "za pierwszym razem od poczatku do konca a za drugim od konca do poczatku" << endl;
			list->print();
		}
		else if (a == 10) {
			int i;
			cout << "Podaj indeks: ";
			cin >> i;
			list->removeAt(i);

			cout << "Lista wyswietlana jest dwukrotnie" << endl;
			cout << "za pierwszym razem od poczatku do konca a za drugim od konca do poczatku" << endl;
			list->print();
		}
		else if (a == 11) {
			cout << "Podaj wartosc elementu: ";
			cin >> a;
			if (list->search(a)) cout << "Element znajduje sie w liscie" << endl;
			else cout << "Element nie znajduje sie w liscie" << endl;
		}
	}
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

	int a;
	while (true) {
		cout << "Binarny kopiec zupelny o rozmiarze: " << heap->getSize() << endl;
		cout << "wybor: ";
		cin >> a;

		if (a == 0) break;
		else if (a == 1) {
			cout << menu;
		}
		else if (a == 2) {
			cout << "Kopiec wyswietlany jest jako tablica zawierajaca wszystkie jego wezly" << endl;
			cout << "element o indeksie 0 jest korzeniem, kolejne 2 elementy sa jego dziecmi, kolejne 4 wnukami itd." << endl;
			heap->print();
		}
		else if (a == 3) {
			int n = 0;
			int* arr = readFromFile(n);
			delete heap;
			heap = new BinaryHeap(arr, n);

			cout << "Kopiec wyswietlany jest jako tablica zawierajaca wszystkie jego wezly" << endl;
			cout << "element o indeksie 0 jest korzeniem, kolejne 2 elementy sa jego dziecmi, kolejne 4 wnukami itd." << endl;
			heap->print();
		}
		else if (a == 4) {
			cout << "Podaj wartosc elementu: ";
			cin >> a;
			try {
				heap->add(a);
			}
			catch (exception e) {
				cout << "Przekroczono rozmiar tablicy, nie mozna dodac kolejnego elementu" << endl;
			}

			cout << "Kopiec wyswietlany jest jako tablica zawierajaca wszystkie jego wezly" << endl;
			cout << "element o indeksie 0 jest korzeniem, kolejne 2 elementy sa jego dziecmi, kolejne 4 wnukami itd." << endl;
			heap->print();

		}
		else if (a == 5) {
			cout << "Podaj wartosc elementu: ";
			cin >> a;
			heap->remove(a);

			cout << "Kopiec wyswietlany jest jako tablica zawierajaca wszystkie jego wezly" << endl;
			cout << "element o indeksie 0 jest korzeniem, kolejne 2 elementy sa jego dziecmi, kolejne 4 wnukami itd." << endl;
			heap->print();
		}
		else if (a == 6) {
			cout << "Podaj wartosc elementu: ";
			cin >> a;
			if (heap->search(a)) cout << "Element znajduje sie w kopcu" << endl;
			else cout << "Element nie znajduje sie w kopcu" << endl;
		}
	}
}

void useBinarySearchTree() {
	BinarySearchTree* tree = new BinarySearchTree(NULL, 0);
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

	int a;
	while (true) {
		cout << "Binarne drzewo poszukiwan o rozmiarze: " << tree->getSize() << endl;
		cout << "wybor: ";
		cin >> a;

		if (a == 0) break;
		else if (a == 1) {
			cout << menu;
		}
		else if (a == 2) {
			cout << "Drzewo wyswietlane jest weze po wezle zaczynajac od korzenia" << endl;
			cout << "Kazda linijka zawiera wartosc wezla i wartosci jego lewego i prawego dziecka" << endl;
			tree->print();
		}
		else if (a == 3) {
			int n = 0;
			int* arr = readFromFile(n);
			delete tree;
			tree = new BinarySearchTree(arr, n);

			cout << "Drzewo wyswietlane jest weze po wezle zaczynajac od korzenia" << endl;
			cout << "Kazda linijka zawiera wartosc wezla i wartosci jego lewego i prawego dziecka" << endl;
			tree->print();
		}
		else if (a == 4) {
			cout << "Podaj wartosc elementu: ";
			cin >> a;
			tree->add(a);

			cout << "Drzewo wyswietlane jest weze po wezle zaczynajac od korzenia" << endl;
			cout << "Kazda linijka zawiera wartosc wezla i wartosci jego lewego i prawego dziecka" << endl;
			tree->print();

		}
		else if (a == 5) {
			cout << "Podaj wartosc elementu: ";
			cin >> a;
			tree->remove(a);

			cout << "Drzewo wyswietlane jest weze po wezle zaczynajac od korzenia" << endl;
			cout << "Kazda linijka zawiera wartosc wezla i wartosci jego lewego i prawego dziecka" << endl;
			tree->print();
		}
		else if (a == 6) {
			cout << "Podaj wartosc elementu: ";
			cin >> a;
			if (tree->search(a)) cout << "Element znajduje sie w drzewie" << endl;
			else cout << "Element nie znajduje sie w drzewie" << endl;
		}
		else if (a == 7) {
			tree->rebalanceTree();
			cout << "Drzewo wyswietlane jest weze po wezle zaczynajac od korzenia" << endl;
			cout << "Kazda linijka zawiera wartosc wezla i wartosci jego lewego i prawego dziecka" << endl;
			tree->print();
			
		}
	}
}

void useRedBlackTree() {
	RedBlackTree* tree = new RedBlackTree(NULL, 0);
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

	int a;
	while (true) {
		cout << "Drzewo czerwono czarne o rozmiarze: " << tree->getSize() << endl;
		cout << "wybor: ";
		cin >> a;

		if (a == 0) break;
		else if (a == 1) {
			cout << menu;
		}
		else if (a == 2) {
			cout << "Drzewo wyswietlane jest wezel po wezle zaczynajac od korzenia" << endl;
			cout << "Kazda linijka zawiera wartosc wezla, jego kolor i kolejno wartosci jego lewego i prawego dziecka" << endl;
			tree->print();
		}
		else if (a == 3) {
			int n = 0;
			int* arr = readFromFile(n);
			delete tree;
			tree = new RedBlackTree(arr, n);

			cout << "Drzewo wyswietlane jest wezel po wezle zaczynajac od korzenia" << endl;
			cout << "Kazda linijka zawiera wartosc wezla, jego kolor i kolejno wartosci jego lewego i prawego dziecka" << endl;
			tree->print();
		}
		else if (a == 4) {
			cout << "Podaj wartosc elementu: ";
			cin >> a;
			tree->add(a);

			cout << "Drzewo wyswietlane jest wezel po wezle zaczynajac od korzenia" << endl;
			cout << "Kazda linijka zawiera wartosc wezla, jego kolor i kolejno wartosci jego lewego i prawego dziecka" << endl;
			tree->print();

		}
		else if (a == 5) {
			cout << "Podaj wartosc elementu: ";
			cin >> a;
			tree->remove(a);

			cout << "Drzewo wyswietlane jest wezel po wezle zaczynajac od korzenia" << endl;
			cout << "Kazda linijka zawiera wartosc wezla, jego kolor i kolejno wartosci jego lewego i prawego dziecka" << endl;
			tree->print();
		}
		else if (a == 6) {
			cout << "Podaj wartosc elementu: ";
			cin >> a;
			if (tree->search(a)) cout << "Element znajduje sie w drzewie" << endl;
			else cout << "Element nie znajduje sie w drzewie" << endl;
		}
	}
}

void useAVLTree() {
	AVLTree* tree = new AVLTree(NULL, 0);
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

	int a;
	while (true) {
		cout << "Drzewo AVL o rozmiarze: " << tree->getSize() << endl;
		cout << "wybor: ";
		cin >> a;

		if (a == 0) break;
		else if (a == 1) {
			cout << menu;
		}
		else if (a == 2) {
			cout << "Drzewo wyswietlane jest weze po wezle zaczynajac od korzenia" << endl;
			cout << "Kazda linijka zawiera wartosc wezla i wartosci jego lewego i prawego dziecka" << endl;
			tree->print();
		}
		else if (a == 3) {
			int n = 0;
			int* arr = readFromFile(n);
			delete tree;
			tree = new AVLTree(arr, n);

			cout << "Drzewo wyswietlane jest weze po wezle zaczynajac od korzenia" << endl;
			cout << "Kazda linijka zawiera wartosc wezla i wartosci jego lewego i prawego dziecka" << endl;
			tree->print();
		}
		else if (a == 4) {
			cout << "Podaj wartosc elementu: ";
			cin >> a;
			tree->add(a);

			cout << "Drzewo wyswietlane jest weze po wezle zaczynajac od korzenia" << endl;
			cout << "Kazda linijka zawiera wartosc wezla i wartosci jego lewego i prawego dziecka" << endl;
			tree->print();

		}
		else if (a == 5) {
			cout << "Podaj wartosc elementu: ";
			cin >> a;
			tree->remove(a);

			cout << "Drzewo wyswietlane jest weze po wezle zaczynajac od korzenia" << endl;
			cout << "Kazda linijka zawiera wartosc wezla i wartosci jego lewego i prawego dziecka" << endl;
			tree->print();
		}
		else if (a == 6) {
			cout << "Podaj wartosc elementu: ";
			cin >> a;
			if (tree->search(a)) cout << "Element znajduje sie w drzewie" << endl;
			else cout << "Element nie znajduje sie w drzewie" << endl;
		}
	}
}

