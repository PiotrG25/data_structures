#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <iomanip>
#include <chrono>
#include <fstream>

#include "Array.h"
#include "Doubly Linked List.h"
#include "Binary Heap.h"
#include "Binary Search Tree.h"
#include "Red Black Tree.h"
#include "AVL Tree.h"




void testArray(int n, int samples);

void testDoublyLinkedList(int n, int samples);


// makes random array
int* makeRandomArray(int n);

// random pisitive integer
int random();


#endif