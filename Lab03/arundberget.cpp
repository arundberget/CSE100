#include <iostream>
#include <climits>

using namespace std;

int maxCrossing(int* list, int left, int mid, int right) { // finds max subarray sum that crosses mid
    int lSum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= left; i--) {
        sum += list[i];
        if (sum > lSum) { // finds max sum of left subarray
            lSum = sum;
        }
    }

    int rSum = INT_MIN;
    sum = 0; // reset sum for right
    for (int i = mid + 1; i <= right; i++) { // find max sum of right subarray
        sum += list[i];
        if (sum > rSum) {
            rSum = sum;
        }
    }
    return lSum + rSum;
}

int maxSubarray(int* list, int left, int right) {
    if (left == right) {
        return list[left]; // returns if only one
    }

    int mid = (left + right) / 2;

    int lMax = maxSubarray(list, left, mid); // calls max subarray function for left half
    int rMax = maxSubarray(list, mid + 1, right); // calls max subarray function for right half
    int cMax = maxCrossing(list, left, mid, right); // calls max crossing function

    return max(lMax, max(rMax, cMax));
}

int main() {
    int* list; // declare list pointer
    int size = 0;

    cin >> size;

    list = new int[size];

    for (int i = 0; i < size; i++) { // input into array
        cin >> list[i];
    }

    cout << maxSubarray(list, 0, size - 1);

    delete[] list; // deallocate

    return 0;
}