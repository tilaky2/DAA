#include <stdio.h>
void rearrangeArray(int arr[], int n) {
    int result[n];  
    int left = 0, right = n - 1, index = 0;

    while (left <= right) {
        if (index % 2 == 0) {
            result[index] = arr[right];
            right--;
        } else { 
            result[index] = arr[left];
            left++;
        }
        index++;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = result[i];
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    rearrangeArray(arr, n);
    printf("Rearranged array in maximum-minimum form:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
