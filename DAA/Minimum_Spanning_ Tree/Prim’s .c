/*
Objective:
Use Prim's algorithm to compute the Minimum Spanning Tree (MST)
of a weighted graph by progressively selecting minimum edges.
*/

#include <stdio.h>

#define V 5   // Total number of vertices

// Function to get the vertex with the smallest key value
int findMinVertex(int key[], int visited[])
{
    int min = 999999;
    int minIndex = -1;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && key[i] < min)
        {
            min = key[i];
            minIndex = i;
        }
    }

    return minIndex;
}

// Function to print MST details and its total weight
void displayMST(int parent[], int graph[V][V])
{
    printf("\nMinimum Spanning Tree using Prim's Algorithm:\n");
    printf("Edge   |   Cost\n");

    int totalCost = 0;

    for (int i = 1; i < V; i++)
    {
        printf("%d -> %d   |   %d\n", parent[i], i, graph[i][parent[i]]);
        totalCost += graph[i][parent[i]];
    }

    printf("Overall MST cost: %d\n", totalCost);
}

// Function implementing Prim's algorithm
void applyPrim(int graph[V][V])
{
    int parent[V];   // Stores MST structure
    int key[V];      // Holds minimum edge weights
    int visited[V];  // Marks visited vertices

    // Initialize values
    for (int i = 0; i < V; i++)
    {
        key[i] = 999999;
        visited[i] = 0;
    }

    key[0] = 0;     // Begin from vertex 0
    parent[0] = -1; // Root of MST

    for (int count = 0; count < V - 1; count++)
    {
        int u = findMinVertex(key, visited);
        visited[u] = 1;

        // Update keys of adjacent vertices
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    displayMST(parent, graph);
}

int main()
{
    // Graph represented as adjacency matrix
    int graph[V][V] = {
        {0, 2, 3, 0, 0},
        {2, 0, 5, 3, 0},
        {3, 5, 0, 0, 4},
        {0, 3, 0, 0, 2},
        {0, 0, 4, 2, 0}
    };

    applyPrim(graph);

    return 0;
}
