#include <stdio.h>
int findOccurrence(int arr[], int n, int key, int findFirst) {
    int low = 0, high = n - 1, result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            result = mid;
            if (findFirst)
                high = mid - 1; 
            else
                low = mid + 1; 
        } else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return result;
}
int main() {
    int arr[] = {2, 4, 10, 10, 10, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 10;

    int first = findOccurrence(arr, n, key, 1);
    int last = findOccurrence(arr, n, key, 0);

    printf("First occurrence: %d\n", first);
    printf("Last occurrence: %d\n", last);

    return 0;
}
