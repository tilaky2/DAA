#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
void findPairsWithDifferenceK(int arr[], int n, int k) {
    qsort(arr, n, sizeof(int), compare);

    int left = 0, right = 1;

    while (right < n) {
        int diff = arr[right] - arr[left];
        
        if (diff == k) {
            printf("Pair: (%d, %d)\n", arr[left], arr[right]);
            left++;
            right++;
        } else if (diff < k) {
            right++;
        } else {
            left++;
            if (left == right) {
                right++;
            }
        }
    }
}
int main() {
    int arr[] = {1, 5, 3, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    printf("Pairs with difference %d:\n", k);
    findPairsWithDifferenceK(arr, n, k);
    return 0;
}
