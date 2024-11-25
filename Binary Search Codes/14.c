#include <stdio.h>
int findOddOccurringElement(int arr[], int n) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if ((mid == 0 || arr[mid] != arr[mid - 1]) && (mid == n - 1 || arr[mid] != arr[mid + 1])) {
            return arr[mid];
        }
        if (mid % 2 == 0) {
            if (arr[mid] == arr[mid + 1]) {
                low = mid + 2;  
            } else {
                high = mid - 1;
            }
        } 
        else {
            if (arr[mid] == arr[mid - 1]) {
                low = mid + 1; 
            } else {
                high = mid - 2;
            }
        }
    }
    return -1;  
}
int main() {
    int arr[] = {1, 1, 2, 2, 3, 3, 4}; 
    int n = sizeof(arr) / sizeof(arr[0]);

    int oddElement = findOddOccurringElement(arr, n);
    printf("The odd occurring element is: %d\n", oddElement);

    return 0;
}
