#include <stdio.h>
#define INFINITY 9999
#define MAX 10
void dijkstra(int graph[MAX][MAX], int vertices, int start);
int main() {
    int graph[MAX][MAX], n, start;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    printf("Enter the starting node: ");
    scanf("%d", &start);
    dijkstra(graph, n, start);
    return 0;
}
void dijkstra(int graph[MAX][MAX], int vertices, int start) {
    int cost[MAX][MAX], distance[MAX], predecessor[MAX];
    int visited[MAX] = {0};
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (graph[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = graph[i][j];
        }
    }
    for (int i = 0; i < vertices; i++) {
        distance[i] = cost[start][i];
        predecessor[i] = start;
    }
    distance[start] = 0;
    visited[start] = 1;
    for (int count = 1; count < vertices - 1; count++) {
        int minDistance = INFINITY, nextNode = -1;
        for (int i = 0; i < vertices; i++) {
            if (distance[i] < minDistance && !visited[i]) {
                minDistance = distance[i];
                nextNode = i;
            }
        }
        visited[nextNode] = 1;
        for (int i = 0; i < vertices; i++) {
            if (!visited[i] && minDistance + cost[nextNode][i] < distance[i]) {
                distance[i] = minDistance + cost[nextNode][i];
                predecessor[i] = nextNode;
            }
        }
    }
    for (int i = 0; i < vertices; i++) {
        if (i != start) {
            printf("\nDistance of node %d = %d", i, distance[i]);
            printf("\nPath: %d", i);
            int j = i;
            do {
                j = predecessor[j];
                printf(" <- %d", j);
            } while (j != start);
        }
    }
}