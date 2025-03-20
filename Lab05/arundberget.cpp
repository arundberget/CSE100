#include <iostream>
#include <cstdlib>

using namespace std;

int randPartition(int* list, int left, int right) {
    int i = rand() % (right - left + 1) + left; // random index
    swap(list[right], list[i]); // swap pivot with last

    int pivot = list[right];
    int j = left - 1;

    for (int k = left; k < right; k++) {
        if (list[k] <= pivot) {
            j++;
            swap(list[j], list[k]); // swap smaller with j element
        }
    }
    swap(list[j + 1], list[right]); // swap pivot
    return j + 1; // pivot
}

void randQuickSort(int* list, int left, int right) {
    if (left < right) {
        int j = randPartition(list, left, right); // partition to get pivot
        randQuickSort(list, left, j - 1);
        randQuickSort(list, j + 1, right);
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

    randQuickSort(list, 0, size - 1); // call quicksort

    for (int i = 0; i < size; i++) { // output with correct format
        cout << list[i] << ";";
    }

    delete[] list;

    return 0;
}