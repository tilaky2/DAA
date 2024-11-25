#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
void findKClosestElements(int arr[], int n, int target, int k) {
    qsort(arr, n, sizeof(int), compare);
    int left = 0, right = n - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    left = (arr[left] < target) ? left : left - 1;
    right = left + 1;
    printf("The %d closest elements to %d are: ", k, target);
    
    for (int i = 0; i < k; i++) {
        if (left >= 0 && right < n) {
            if (abs(arr[left] - target) <= abs(arr[right] - target)) {
                printf("%d ", arr[left--]);
            } else {
                printf("%d ", arr[right++]);
            }
        }
        else if (right < n) {
            printf("%d ", arr[right++]);
        }
        else {
            printf("%d ", arr[left--]);
        }
    }
    printf("\n");
}
int main() {
    int arr[] = {1, 5, 9, 10, 12, 15, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    int k = 3;

    findKClosestElements(arr, n, target, k);

    return 0;
}
