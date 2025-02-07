#include <iostream>
using namespace std;

// Function to partition the array using the middle element as pivot
int partition(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;  // Find the middle element
    int pivot = arr[mid];  // Choose the middle element as pivot
    swap(arr[mid], arr[high]);  // Move pivot to the end for partitioning
    
    int i = low - 1;  // Pointer for the smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;  // Increment index of smaller element
            swap(arr[i], arr[j]);  // Swap arr[i] and arr[j]
        }
    }
    swap(arr[i + 1], arr[high]);  // Place pivot at the correct position
    return (i + 1);  // Return the partition index
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array into two halves
        int pi = partition(arr, low, high);
        
        // Recursively sort the two halves
        quickSort(arr, low, pi - 1);  // Left part
        quickSort(arr, pi + 1, high);  // Right part
    }
}

// Function to display the array
void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    display(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    display(arr, n);

    return 0;
}
