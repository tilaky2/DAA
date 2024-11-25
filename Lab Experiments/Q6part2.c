#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int level, profit, weight;
    float bound;
} Node;

int maxProfitBB = 0;

float bound(Node u, int n, int W, int weights[], int values[]) {
    if (u.weight >= W)
        return 0;

    float profit_bound = u.profit;
    int j = u.level + 1;
    int totalWeight = u.weight;

    while (j < n && totalWeight + weights[j] <= W) {
        totalWeight += weights[j];
        profit_bound += values[j];
        j++;
    }

    if (j < n)
        profit_bound += (W - totalWeight) * values[j] / (float)weights[j];

    return profit_bound;
}

void knapsackBranchBound(int W, int weights[], int values[], int n) {
    Node queue[1000];
    int front = 0, rear = 0;

    Node u, v;
    u.level = -1;
    u.profit = u.weight = 0;
    queue[rear++] = u;

    while (front < rear) {
        u = queue[front++];
        if (u.level == -1)
            v.level = 0;
        else
            v.level = u.level + 1;

        if (v.level < n) {
            v.weight = u.weight + weights[v.level];
            v.profit = u.profit + values[v.level];

            if (v.weight <= W && v.profit > maxProfitBB)
                maxProfitBB = v.profit;

            v.bound = bound(v, n, W, weights, values);
            if (v.bound > maxProfitBB)
                queue[rear++] = v;

            v.weight = u.weight;
            v.profit = u.profit;
            v.bound = bound(v, n, W, weights, values);
            if (v.bound > maxProfitBB)
                queue[rear++] = v;
        }
    }
}

int main() {
    int weights[] = {10, 20, 30};
    int values[] = {60, 100, 120};
    int W = 50;
    int n = sizeof(values) / sizeof(values[0]);

    knapsackBranchBound(W, weights, values, n);
    printf("Maximum profit using Branch & Bound: %d\n", maxProfitBB);

    return 0;
}
