#include <iostream>

using namespace std;

void countSort(int list[][10], int size, int pos) {
    int count[4] = {0}; // count array to store digits
    int output[size][10]; // temp array

    for (int i = 0; i < size; i++) {
        int digit = list[i][pos];
        count[digit]++;
    }

    for (int i = 1; i < 4; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        int digit = list[i][pos];
        for (int j = 0; j < 10; j++) {
            output[count[digit] - 1][j] = list[i][j];
        }
        count[digit]--;
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 10; j++) {
            list[i][j] = output[i][j];
        }
    }

}

void radixSort(int list[][10], int size) {
    for (int pos = 9; pos >= 0; pos--) {
        countSort(list, size, pos);
    }

}

void printVectors(int list[][10], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 10; j++) {
            cout << list[i][j];
            if (j != 9) {
                cout << ";";
            }
        }
        cout << ";" << endl;
    }
}

int main() {
    int size = 0;

    cin >> size;

    int list[size][10];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> list[i][j];
        }
    }
    
    radixSort(list, size);

    printVectors(list, size);

    return 0;
}