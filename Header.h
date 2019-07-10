#ifndef Header
#define Header
#include <iostream>
#include <vector>
#include <time.h>       /* time */
using namespace std;
#include <cstdlib>


class Graph
{
public:
    int NumberOfNodes;    // No. of nodes
    vector<vector <int>> adj;    // adj matrix
    int sizeA;
    vector<vector <int>> A;

    Graph(int NumberOfNodes);   // Constructor

    void addEdge(int node1, int node2);   // function to add an edge to graph
    int minDistance(int dist[], bool sptSet[]);
    void printPath(int parent[], int j);
    void printSolution(int dist[], int parent[], int src);
    void dijkstra(int src);
    void createMatrixA();

    //print
    void printAdjMatrix();
    void printA();
};
Graph GraphGenerator(int nodes);


#endif