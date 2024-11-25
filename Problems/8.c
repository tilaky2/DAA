#include <stdio.h>

void findLargestThree(int arr[], int n) {
    int first, second, third;

    if (n < 3) {
        printf("Array should have at least 3 elements.\n");
        return;
    }
    first = second = third = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] > first) {
            third = second;
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] < first) {
            third = second;
            second = arr[i];
        } else if (arr[i] > third && arr[i] < second) {
            third = arr[i];
        }
    }
    printf("The largest three distinct elements are: %d, %d, %d\n", first, second, third);
}

int main() {
    int arr[] = {10, 4, 3, 50, 23, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    findLargestThree(arr, n);
    return 0;
}
