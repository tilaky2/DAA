#include <stdio.h>
int main() {
    int n, i, j, element;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[100]; 

    printf("Enter %d elements:\n", n);
    for (int k = 0; k < n; k++) {
        scanf("%d", &arr[k]);
    }

    printf("Enter the position (0-based index) to insert an element: ");
    scanf("%d", &i);
    printf("Enter the element to insert: ");
    scanf("%d", &element);

    for (int k = n; k > i; k--) {
        arr[k] = arr[k - 1];
    }
    arr[i] = element; 
    n++; 

    printf("Array after insertion:\n");
    for (int k = 0; k < n; k++) {
        printf("%d ", arr[k]);
    }
    printf("\n");

    printf("Enter the position (0-based index) to delete an element: ");
    scanf("%d", &j);

    for (int k = j; k < n - 1; k++) {
        arr[k] = arr[k + 1];
    }
    n--; 

    printf("Array after deletion:\n");
    for (int k = 0; k < n; k++) {
        printf("%d ", arr[k]);
    }
    printf("\n");

    return 0;
}
