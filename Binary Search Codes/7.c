#include <stdio.h>

int searchInNearlySortedArray(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        if (mid - 1 >= low && arr[mid - 1] == key)
            return mid - 1;
        if (mid + 1 <= high && arr[mid + 1] == key)
            return mid + 1;
        if (arr[mid] > key)
            high = mid - 2;  
        else
            low = mid + 2;   
    }

    return -1; 
}
int main() {
    int arr[] = {5, 10, 30, 20, 40, 50, 70}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 20;

    int result = searchInNearlySortedArray(arr, n, key);

    if (result != -1)
        printf("Element %d found at index %d\n", key, result);
    else
        printf("Element %d not found\n", key);

    return 0;
}
