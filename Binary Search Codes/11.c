#include <stdio.h>
void findFloorCeilRecursive(int arr[], int low, int high, int key, int *floor, int *ceil) {
    if (low > high) {
        return;
    }
    int mid = (low + high) / 2;
    if (arr[mid] == key) {
        *floor = arr[mid];
        *ceil = arr[mid];
        return;
    }
    if (arr[mid] > key) {
        *ceil = arr[mid]; 
        findFloorCeilRecursive(arr, low, mid - 1, key, floor, ceil);
    } 
    else {
        *floor = arr[mid]; 
        findFloorCeilRecursive(arr, mid + 1, high, key, floor, ceil);
    }
}
int main() {
    int arr[] = {1, 3, 8, 10, 12, 15};  
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 5;

    int floor = -1, ceil = -1;
    findFloorCeilRecursive(arr, 0, n - 1, key, &floor, &ceil);

    if (floor != -1)
        printf("Floor of %d is %d\n", key, floor);
    else
        printf("No floor exists for %d\n", key);

    if (ceil != -1)
        printf("Ceil of %d is %d\n", key, ceil);
    else
        printf("No ceil exists for %d\n", key);

    return 0;
}
