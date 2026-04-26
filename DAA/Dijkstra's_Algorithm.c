/*
Aim:
To implement Dijkstra’s Algorithm to find the shortest paths
from a selected source vertex to all other vertices in a weighted graph.
*/

#include <stdio.h>

#define V 5
#define INF 999999   // large value representing infinity

// Function to select vertex with minimum distance
int selectMinVertex(int dist[], int visited[])
{
    int min = INF;
    int minIndex = -1;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && dist[i] < min)
        {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// Dijkstra's Algorithm function
void dijkstra(int graph[V][V], int source)
{
    int dist[V];
    int visited[V];

    // initialize arrays
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[source] = 0;

    // main algorithm loop
    for (int count = 0; count < V - 1; count++)
    {
        int u = selectMinVertex(dist, visited);

        if (u == -1)
            break;

        visited[u] = 1;

        // update adjacent vertices
        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && graph[u][v] &&
                dist[u] != INF &&
                dist[v] > dist[u] + graph[u][v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // display output
    printf("\n=== Shortest Path Results ===\n");
    printf("Source Vertex: %d\n\n", source);
    printf("Vertex\tDistance\n");

    for (int i = 0; i < V; i++)
    {
        printf("  %d\t   %d\n", i, dist[i]);
    }

    printf("=============================\n");
}

int main()
{
    int graph[V][V] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    int source = 0;  // you can change this if needed

    printf("Running Dijkstra's Shortest Path Algorithm...\n");

    dijkstra(graph, source);

    printf("Computation finished.\n");

    return 0;
}
