#include <iostream>

using namespace std;

void merge(int* arr, int lSize, int rSize);
void mergeSort(int* arr, int size);

int main(int argc, char** argv) {
    int* list; // declare list pointer
    int size = 0;

    cin >> size;

    list = new int[size];

    for (int i = 0; i < size; i++) { // input into array
        cin >> list[i];
    }

    mergeSort(list, size);

    for (int i = 0; i < size; i++) { // print results after sorting
        cout << list[i] << ";";
    }

    delete[] list; // deallocate memory
    return 0;

}

void merge (int* arr, int lSize, int rSize) {
    int* left = arr;
    int* right = arr + lSize;

    int i = 0; // initialized indices
    int j = 0;
    int k = 0;

    int* temp = new int[lSize + rSize]; // temp pointer

    while (i < lSize && j < rSize) { // merge left and right into temp array
        if (left[i] < right[j]) {
            temp[k] = left[i];
            i++;
        } else {
            temp[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < lSize) {
        temp[k] = left[i];
        i++;
        k++;
    }

    while (j < rSize) {
        temp[k] = right[j];
        j++;
        k++;
    }

    for (i = 0; i < lSize + rSize; i++) {
        arr[i] = temp[i];
    }

    delete[] temp; // deallocate memory
}

void mergeSort(int* arr, int size) {

    if (size <= 1) { // return if array size is 0 or 1 because it would already be sorted
        return;
    }

    int lSize = size / 2;
    int rSize = size - lSize;

    mergeSort(arr, lSize); // recursion
    mergeSort(arr + lSize, rSize);
    merge(arr, lSize, rSize);
}