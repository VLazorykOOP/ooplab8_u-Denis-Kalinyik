#include <iostream>

using namespace std;

const int m = 7;

template<typename T>
void bubble_sort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template<typename T>
int binary_search(T arr[], int n, const T& x) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr1[m] = {5, 2, 9, 1, 5, 6, 8};
    bubble_sort(arr1, m);
    for (int i = 0; i < m; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    int x1 = 5;
    int pos1 = binary_search(arr1, m, x1);
    if (pos1 == -1) {
        cout << "Element not found" << endl;
    } else {
        cout << "Element found at position " << pos1 << endl;
    }

    const char* arr2[m] = {"apple", "banana", "cherry", "grape", "orange", "pear", "strawberry"};
    bubble_sort(arr2, m);
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    const char* x2 = "orange";
    int pos2 = binary_search(arr2, m, x2);
    if (pos2 == -1) {
        cout << "Element not found" << endl;
    } else {
        cout << "Element found at position " << pos2 << endl;
    }

    return 0;
}