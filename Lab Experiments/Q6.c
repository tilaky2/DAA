#include <stdio.h>

int maxProfit = 0;

void knapsackBacktracking(int weights[], int values[], int n, int capacity, int currentProfit, int currentWeight, int index) {
    if (index == n || currentWeight > capacity) {
        if (currentProfit > maxProfit && currentWeight <= capacity)
            maxProfit = currentProfit;
        return;
    }

    knapsackBacktracking(weights, values, n, capacity, currentProfit + values[index], currentWeight + weights[index], index + 1); // Include
    knapsackBacktracking(weights, values, n, capacity, currentProfit, currentWeight, index + 1); // Exclude
}

int main() {
    int weights[] = {10, 20, 30};
    int values[] = {60, 100, 120};
    int capacity = 50;
    int n = sizeof(values) / sizeof(values[0]);

    knapsackBacktracking(weights, values, n, capacity, 0, 0, 0);
    printf("Maximum profit using backtracking: %d\n", maxProfit);

    return 0;
}
