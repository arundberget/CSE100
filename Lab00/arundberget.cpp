#include <iostream>

#define MAX_INT 2147483647

using namespace std;

int main(int argc, char **argv) {
    int* list;
    int size = 0;

    cin >> size;

    list = new int[size];

    int max = list[0];
    int min = list[0];

    for (int i = 0; i < size; i++) {
        cin >> list[i];
    }

    for (int i = 0; i < size; i++) {
        if (list[i] > max) {
            max = list[i];
        }
        if (list[i] < min) {
            min = list[i];
        }
    }

    cout << max << ";" << min;
}
