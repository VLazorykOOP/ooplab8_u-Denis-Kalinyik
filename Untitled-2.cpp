#include <iostream>
#include <algorithm>
#include <cstring>

template <typename T>
void bubbleSort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template <typename T>
int binarySearch(T arr[], int n, T x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

template <>
int binarySearch<char*>(char* arr[], int n, char* x) {
    bubbleSort(arr, n);
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(arr[mid], x);
        if (cmp == 0) {
            return mid;
        }
        if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 30;
    int result = binarySearch(arr, n, x);
    (result == -1) ? std::cout << "Element is not present in array\n" 
                   : std::cout << "Element is present at index " << result << '\n';

    char* strArr[] = {"john", "alex", "doe", "jane", "smith"};
    n = sizeof(strArr) / sizeof(strArr[0]);
    char* str = "doe";
    result = binarySearch(strArr, n, str);
    (result == -1) ? std::cout << "Element is not present in array\n" 
                   : std::cout << "Element is present at index " << result << '\n';
    return 0;
}
