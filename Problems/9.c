#include <stdio.h>
void moveZeroesToEnd(int arr[], int n) {
    int count = 0; 
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[count++] = arr[i];
        }
    }
    while (count < n) {
        arr[count++] = 0;
    }
}
int main() {
    int arr[] = {10, 0, 5, 0, 8, 0, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    moveZeroesToEnd(arr, n);
    printf("Array after moving zeroes to the end:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
