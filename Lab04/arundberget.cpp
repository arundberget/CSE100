#include <iostream>

using namespace std;

void maxHeapify(int* list, int size, int i) {
	int l = 2 * i + 1; // left index
	int r = 2 * i + 2; // right index
	int largest = i; // default current node as largest

	if (l < size && list[l] > list[largest]) { // checks if left child exists and compares to current largest
		largest = l;
	}

	if (r < size && list[r] > list[largest]) { // checks if right child exists and compares to current largest
		largest = r;
	}

	if (largest != i) { // swap if largest isn't in current node
		swap(list[i], list[largest]);
		maxHeapify(list, size, largest);
	}
}

void heapSort(int* list, int size) {
	for (int i = size / 2 - 1; i >= 0; i--) { // build max heap
		maxHeapify(list, size, i);
	}

	for (int i = size - 1; i > 0; i--) { // swaps root with last element repeatedly
		swap(list[0], list[i]);
		maxHeapify(list, i, 0);
	}
}

int main() {
	int* list; // declare list pointer
    int size = 0;

    cin >> size;

    list = new int[size];

    for (int i = 0; i < size; i++) { // input into array
        cin >> list[i];
    }

	heapSort(list, size);

	for (int i = 0; i < size; i++) { // output with correct format
		cout << list[i] << ";";
	}

	delete[] list;

	return 0;
}
