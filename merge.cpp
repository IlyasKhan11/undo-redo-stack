#include <iostream>
using namespace std;

// Merging function with reduced memory overhead
void merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;

    // Merge two sorted halves
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) 
            temp[k++] = arr[i++];
        else 
            temp[k++] = arr[j++];
    }

    // Copy remaining elements of left subarray
    while (i <= mid) 
        temp[k++] = arr[i++];

    // Copy remaining elements of right subarray
    while (j <= right) 
        temp[k++] = arr[j++];

    // Copy merged elements back to original array
    for (int x = left; x <= right; x++) 
        arr[x] = temp[x];
}

// Optimized Merge Sort function
void mergeSort(int arr[], int temp[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;  // Prevent overflow

        mergeSort(arr, temp, left, mid);
        mergeSort(arr, temp, mid + 1, right);

        merge(arr, temp, left, mid, right);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver code
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp[n];  // Temporary array to reduce memory allocations

    cout << "Original array: ";
    printArray(arr, n);

    mergeSort(arr, temp, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
