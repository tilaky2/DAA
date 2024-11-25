#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int start;
    int finish;
} Activity;

int compare(const void *a, const void *b) {
    return ((Activity *)a)->finish - ((Activity *)b)->finish;
}

void activitySelection(Activity activities[], int n) {
    qsort(activities, n, sizeof(Activity), compare);

    printf("Selected activities:\n");
    int lastFinish = activities[0].finish;
    printf("Activity (Start: %d, Finish: %d)\n", activities[0].start, activities[0].finish);

    for (int i = 1; i < n; i++) {
        if (activities[i].start >= lastFinish) {
            printf("Activity (Start: %d, Finish: %d)\n", activities[i].start, activities[i].finish);
            lastFinish = activities[i].finish;
        }
    }
}

int main() {
    Activity activities[] = {{1, 3}, {2, 5}, {4, 6}, {6, 7}, {5, 8}, {8, 9}};
    int n = sizeof(activities) / sizeof(activities[0]);

    activitySelection(activities, n);

    return 0;
}
