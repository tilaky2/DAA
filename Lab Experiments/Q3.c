#include <stdio.h>
#include <limits.h>
#define INF INT_MAX
#define V 5

void dijkstra(int graph[V][V], int src) {
    int dist[V], visited[V] = {0};
    for (int i = 0; i < V; i++) dist[i] = INF;
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = -1;
        for (int i = 0; i < V; i++)
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;

        visited[u] = 1;
        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printf("Dijkstra's shortest distances from source %d:\n", src);
    for (int i = 0; i < V; i++)
        printf("To %d: %d\n", i, dist[i]);
}

void bellmanFord(int graph[V][3], int E, int src) {
    int dist[V];
    for (int i = 0; i < V; i++) dist[i] = INF;
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph[j][0];
            int v = graph[j][1];
            int weight = graph[j][2];
            if (dist[u] != INF && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    printf("Bellman-Ford shortest distances from source %d:\n", src);
    for (int i = 0; i < V; i++)
        printf("To %d: %d\n", i, dist[i]);
}

int main() {
    int graph[V][V] = {{0, 10, 0, 0, 0}, {0, 0, 3, 0, 5}, {0, 0, 0, 2, 0}, {0, 0, 0, 0, 6}, {0, 0, 0, 0, 0}};
    dijkstra(graph, 0);

    int edges[][3] = {{0, 1, 10}, {1, 2, 3}, {2, 3, 2}, {1, 4, 5}, {3, 4, 6}};
    bellmanFord(edges, 5, 0);

    return 0;
}
