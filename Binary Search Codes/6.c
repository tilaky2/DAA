#include <stdio.h>

void findFloorCeil(int arr[], int n, int key, int *floor, int *ceil) {
    int low = 0, high = n - 1;
    *floor = -1;
    *ceil = -1;
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            *floor = arr[mid];  
            *ceil = arr[mid];
            return;
        }

        if (arr[mid] < key) {
            *floor = arr[mid];
            low = mid + 1;
        } else {
            *ceil = arr[mid];
            high = mid - 1;
        }
    }
}

int main() {
    int arr[] = {1, 3, 8, 10, 12, 15};  
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 5; 

    int floor, ceil;
    findFloorCeil(arr, n, key, &floor, &ceil);

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
