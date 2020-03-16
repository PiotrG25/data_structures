
#include "Test.h"

int random() {
	return (rand() << 16) + (rand() << 1) + (rand() % 2);
}

int* makeRandomArray(int n) {
	int* arr = new int[n];
	for (int i = 0; i < n; ++i) arr[i] = i + 1;

	int len = n, i = 0;
	while (len > 1) {
		int r = random() % len + i;

		int t = arr[i];
		arr[i] = arr[r];
		arr[r] = t;

		++i;
		--len;
	}
	return arr;
}

void testArray(int n, int samples) {

	std::cout << "Array test for " << n << " elements and " << samples << " samples" << std::endl;


	Array* array;
	double* sampleResults = new double[samples];
	double result;
	std::ofstream os;


	// 
	// addFirst

	for (int i = 0; i < samples; ++i) {

		int* arr = makeRandomArray(n + 1);
		array = new Array(arr, n);

		auto t1 = std::chrono::high_resolution_clock::now();
		array->addFirst(arr[n]);
		auto t2 = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> t = t2 - t1;

		sampleResults[i] = t.count();
	}

	result = 0;
	for (int i = 0; i < samples; ++i) result += sampleResults[i];
	result /= samples;
	std::cout << std::setw(20) << "addFirst: " << result << std::endl;


	os.open("addFirst.txt", std::ios::out | std::ios::app);
	os << std::fixed << std::setprecision(12) << result << std::endl;
	os.close();

	// addLast

	for (int i = 0; i < samples; ++i) {

		int* arr = makeRandomArray(n + 1);
		array = new Array(arr, n);

		auto t1 = std::chrono::high_resolution_clock::now();
		array->addLast(arr[n]);
		auto t2 = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> t = t2 - t1;

		sampleResults[i] = t.count();
	}

	result = 0;
	for (int i = 0; i < samples; ++i) result += sampleResults[i];
	result /= samples;
	std::cout << std::setw(20) << "addLast: " << result << std::endl;


	os.open("addLast.txt", std::ios::out | std::ios::app);
	os << std::fixed << std::setprecision(12) << result << std::endl;
	os.close();

	// addAt

	for (int i = 0; i < samples; ++i) {

		int* arr = makeRandomArray(n + 1);
		array = new Array(arr, n);

		auto t1 = std::chrono::high_resolution_clock::now();
		array->addAt(arr[n], random() % (n + 1));
		auto t2 = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> t = t2 - t1;

		sampleResults[i] = t.count();
	}

	result = 0;
	for (int i = 0; i < samples; ++i) result += sampleResults[i];
	result /= samples;
	std::cout << std::setw(20) << "addAt: " << result << std::endl;


	os.open("addAt.txt", std::ios::out | std::ios::app);
	os << std::fixed << std::setprecision(12) << result << std::endl;
	os.close();


	// removeFirst

	for (int i = 0; i < samples; ++i) {

		int* arr = makeRandomArray(n + 1);
		array = new Array(arr, n);

		auto t1 = std::chrono::high_resolution_clock::now();
		array->removeFirst();
		auto t2 = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> t = t2 - t1;

		sampleResults[i] = t.count();
	}

	result = 0;
	for (int i = 0; i < samples; ++i) result += sampleResults[i];
	result /= samples;
	std::cout << std::setw(20) << "removeFirst: " << result << std::endl;


	os.open("removeFirst.txt", std::ios::out | std::ios::app);
	os << std::fixed << std::setprecision(12) << result << std::endl;
	os.close();

	// removeLast

	for (int i = 0; i < samples; ++i) {

		int* arr = makeRandomArray(n + 1);
		array = new Array(arr, n);

		auto t1 = std::chrono::high_resolution_clock::now();
		array->removeLast();
		auto t2 = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> t = t2 - t1;

		sampleResults[i] = t.count();
	}

	result = 0;
	for (int i = 0; i < samples; ++i) result += sampleResults[i];
	result /= samples;
	std::cout << std::setw(20) << "removeLast: " << result << std::endl;


	os.open("removeLast.txt", std::ios::out | std::ios::app);
	os << std::fixed << std::setprecision(12) << result << std::endl;
	os.close();

	// removeAt

	for (int i = 0; i < samples; ++i) {

		int* arr = makeRandomArray(n + 1);
		array = new Array(arr, n);

		auto t1 = std::chrono::high_resolution_clock::now();
		array->removeAt(random() % n);
		auto t2 = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> t = t2 - t1;

		sampleResults[i] = t.count();
	}

	result = 0;
	for (int i = 0; i < samples; ++i) result += sampleResults[i];
	result /= samples;
	std::cout << std::setw(20) << "removeAt: " << result << std::endl;


	os.open("removeAt.txt", std::ios::out | std::ios::app);
	os << std::fixed << std::setprecision(12) << result << std::endl;
	os.close();


	// search

	for (int i = 0; i < samples; ++i) {

		int* arr = makeRandomArray(n + 1);
		array = new Array(arr, n);

		auto t1 = std::chrono::high_resolution_clock::now();
		array->search(arr[random() % n]);
		auto t2 = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> t = t2 - t1;

		sampleResults[i] = t.count();
	}

	result = 0;
	for (int i = 0; i < samples; ++i) result += sampleResults[i];
	result /= samples;
	std::cout << std::setw(20) << "search: " << result << std::endl;


	os.open("search.txt", std::ios::out | std::ios::app);
	os << std::fixed << std::setprecision(12) << result << std::endl;
	os.close();
}