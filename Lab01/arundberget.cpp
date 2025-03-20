#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    int* list; // declare list pointer
    int size = 0;

    cin >> size;

    list = new int[size];

    for (int i = 0; i < size; i++) { // input into array
        cin >> list[i];
    }

    for (int i = 1; i < size; i++) { // start from second element
        int curr = list[i];
        int j = i - 1;

        while (j >= 0 && list[j] > curr) {
            list[j + 1] = list[j]; // shift to right
            j--;
        }
        list[j + 1] = curr; // insert

        for (int k = 0; k <= i; k++) {
            cout << list[k] << ";"; // print current list with ; after each value

        }
        cout << endl;
    }

    delete[] list; // free memory
}