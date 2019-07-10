// A C / C++ program for Dijkstra's single source shortest
// path algorithm. The program is for adjacency matrix
// representation of the graph.
#include <stdio.h>
#include <limits.h>
#include "Header.h"

// A utility function to find the vertex with minimum distance
// value, from the set of vertices not yet included in shortest
// path tree
int Graph::minDistance(int dist[], bool sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < NumberOfNodes; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    
    return min_index;
}
 
// Function to print shortest path from source to j
// using parent array
void Graph::printPath(int parent[], int j)
{
    // Base Case : If j is source
    if (parent[j] == -1)
        return;
 
    printPath(parent, parent[j]);
 
    printf("%d ", j);
}
 
// A utility function to print the constructed distance
// array
void Graph::printSolution(int dist[], int parent[],int src)
{
    printf("Vertex\t  Distance\tPath");
    for (int i = 0; i < NumberOfNodes; i++)
    {
        printf("\n%d -> %d \t\t %d\t\t%d ", src, i, dist[i], src);
        printPath(parent, i);
    }
    printf("\n");
}
 
// Funtion that implements Dijkstra's single source shortest path
// algorithm for a graph represented using adjacency matrix
// representation
void Graph::dijkstra(int src)
{
    int dist[NumberOfNodes];  // The output array. dist[i] will hold
                  // the shortest distance from src to i
 
    // sptSet[i] will true if vertex i is included / in shortest
    // path tree or shortest distance from src to i is finalized
    bool sptSet[NumberOfNodes];
 
    // Parent array to store shortest path tree
    int parent[NumberOfNodes];
 
    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < NumberOfNodes; i++)
    {
        parent[i] = -1;
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
 
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
 
    // Find shortest path for all vertices
    for (int count = 0; count < NumberOfNodes-1; count++)
    {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed. u is always equal to src
        // in first iteration.
        int u = minDistance(dist, sptSet);
 
        // Mark the picked vertex as processed
        sptSet[u] = true;
 
        // Update dist value of the adjacent vertices of the
        // picked vertex.
        for (int v = 0; v < NumberOfNodes; v++)
 
            // Update dist[v] only if is not in sptSet, there is
            // an edge from u to v, and total weight of path from
            // src to v through u is smaller than current value of
            // dist[v]
            if (!sptSet[v] && adj[u][v] &&
                dist[u] + adj[u][v] < dist[v])
            {
                parent[v]  = u;
                dist[v] = dist[u] + adj[u][v];
            }  
    }
 
    // print the constructed distance array
    printSolution(dist, parent, src);
    // creating Matrix A

    int temp;
    for(int current_dest = 0; current_dest < NumberOfNodes; current_dest++) {
        temp = current_dest;
        while(temp != src) {
            A[parent[temp] * NumberOfNodes + temp][src * NumberOfNodes + current_dest] = 1;
            A[temp * NumberOfNodes + parent[temp]][current_dest * NumberOfNodes + src] = 1;
            temp = parent[temp];
        }
    }
}