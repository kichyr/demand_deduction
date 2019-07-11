#include <iostream>
#include <time.h>       /* time */
using namespace std;
#include "Header.h"
#include <cstdlib>

void Graph::initGraph(int NumberOfNodes)
{
    this->NumberOfNodes = NumberOfNodes;
    adj = std::vector<vector<int>>(NumberOfNodes, std::vector<int>(NumberOfNodes, 0));
    sizeA = NumberOfNodes * NumberOfNodes;
    A = std::vector<vector<float>>(sizeA, std::vector<float>(sizeA, 0.0));
}

void Graph::addEdge(int node1, int node2)
{
    adj[node1][node2] = 1;
    adj[node2][node1] = 1;
}

void Graph::createMatrixA() {
    printf("----------------Pathes--------------\n");
    for(int i = 0; i < NumberOfNodes; i++) {
        dijkstra(i);
    }
}

void Graph::printA() {
    std::cout << "-------------A matrix:-------------\n"; 
    for(int i = 0; i < sizeA; i++) {
        for(int j = 0; j < sizeA; j++) {
            cout << A[i][j];
        }
        std::cout << std::endl;
    }
}

void Graph::printAdjMatrix() {
    std::cout << "-------------adj matrix:-------------\n";
    for(int i = 0; i < NumberOfNodes; i++) {
        for(int j = 0; j < NumberOfNodes; j++) {
            cout << adj[i][j];
        }
        std::cout << std::endl;
    }
}
 
Graph GraphGeneratorFromFile(int* nodes) {
    FILE * fp;
	fp = fopen ("Graph.txt","r");
    fscanf(fp, "%d", nodes);
    Graph g;
    g.initGraph(*nodes);

    int v1, v2;
    for(int i = 0; EOF != fscanf(fp, "%d", &v1); i++) {
            fscanf(fp, "%d", &v2);
            g.addEdge(v1, v2);
    }
    return g;
}

Graph GraphGenerator(int* nodes, bool fromFile)
{
    if(fromFile) {
        return GraphGeneratorFromFile(nodes);
    }
	FILE * fp;  
	fp = fopen ("Graph.txt","w");
    Graph g;
    g.initGraph(*nodes);
    int i,numofedges,v1,v2;//v1 is node1 , v2 is node2
    srand (time(NULL));
    numofedges = rand() % (*nodes / 3) + 1;//range 1 to n^2
    fprintf(fp, "%d\n", *nodes);
    //satisfy the connectivity, the min edges is nodes -1
    for(i = 0; i < *nodes-1; i++)
    {
        g.addEdge(i,i+1);
        fprintf(fp, "%d\t%d\n",i,i+1);
    }
   
    for(i = 0; i <= numofedges; i++)
    {
        v1 = rand() % *nodes;
        v2 = rand() % *nodes;
        if(v1 == v2)
        {
            numofedges++;
            continue;
        }
        else
        {
            g.addEdge(v1,v2);
            fprintf(fp, "%d\t%d\n",v1,v2);
        }
    }
    return g;
}
 