/*
Objective:
Apply Kruskal's method to determine the Minimum Spanning Tree (MST)
of a weighted graph using a greedy selection technique.
*/

#include <stdio.h>

#define V 5   // Total vertices in the graph
#define E 6   // Total edges in the graph

int parent[V];  // Array for union-find structure

// Function to locate the root of a vertex
int findRoot(int vertex)
{
    while (parent[vertex] != vertex)
    {
        vertex = parent[vertex];
    }
    return vertex;
}

// Function to merge two subsets
void unionSets(int u, int v)
{
    int rootU = findRoot(u);
    int rootV = findRoot(v);
    parent[rootU] = rootV;
}

// Function to arrange edges in ascending order of weight (Bubble Sort)
void sortByWeight(int edgeList[E][3])
{
    for (int i = 0; i < E - 1; i++)
    {
        for (int j = 0; j < E - i - 1; j++)
        {
            if (edgeList[j][2] > edgeList[j + 1][2])
            {
                // Swap complete edge details
                for (int k = 0; k < 3; k++)
                {
                    int temp = edgeList[j][k];
                    edgeList[j][k] = edgeList[j + 1][k];
                    edgeList[j + 1][k] = temp;
                }
            }
        }
    }
}

// Implementation of Kruskal's algorithm
void applyKruskal(int edgeList[E][3])
{
    sortByWeight(edgeList);

    // Initialize each vertex as its own parent
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }

    int edgeCount = 0;
    int totalCost = 0;

    printf("Selected edges in the Minimum Spanning Tree:\n");

    for (int i = 0; i < E && edgeCount < V - 1; i++)
    {
        int u = edgeList[i][0];
        int v = edgeList[i][1];
        int weight = edgeList[i][2];

        // Ensure no cycle is formed before adding edge
        if (findRoot(u) != findRoot(v))
        {
            printf("Edge %d - %d with cost %d added\n", u, v, weight);
            unionSets(u, v);
            totalCost += weight;
            edgeCount++;
        }
    }

    printf("Final MST cost: %d\n", totalCost);
}

int main()
{
    // Edge representation: {start, end, weight}
    int edges[E][3] = {
        {0, 1, 2}, {0, 2, 3}, {1, 2, 5},
        {1, 3, 3}, {2, 4, 4}, {3, 4, 2}
    };

    applyKruskal(edges);

    return 0;
}
