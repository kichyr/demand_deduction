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
    vector<vector <double>> A;

    void initGraph(int NumberOfNodes);   // Constructor

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
Graph GraphGenerator(int* nodes, bool fromFile);


class SimulatorTask
{
public:
    int NumberOfNodes;    // No. of nodes
    int sizeA;
    vector<int> X;
    vector<double> Y;
    int rangeOfFlow;
    Graph G;

    void generateInstanceOfTask(int NumberOfNodes, int rangeOfFlow, bool fromFile) {
        G = GraphGenerator(&NumberOfNodes, fromFile);
        G.printAdjMatrix();
        G.createMatrixA();
        this->rangeOfFlow = rangeOfFlow;
        this->NumberOfNodes = NumberOfNodes;
        sizeA = NumberOfNodes * NumberOfNodes;
        
        X = vector<int>(sizeA, 0);
        Y = vector<double>(sizeA, 0);

        genRandomFlow();
        genY();
        //fixing matrix A
        for(int i = 0; i < NumberOfNodes;i++)
            for(int j = 0; j < sizeA; j++)
                G.A[j][i*NumberOfNodes+i] = 9;
        
        std::cout << "\n---------generated vector X----------:" << std::endl;
        for(int i = 0; i < sizeA; i++)
            std::cout << X[i] << " ";
        std::cout << std::endl;
        std::cout << "\n---------generated vector Y----------:" << std::endl;
        for(int i = 0; i < sizeA; i++)
            std::cout << Y[i] << " ";
        std::cout << std::endl;
    }

    void genRandomFlow() {
        srand (time(NULL));
        int k = 0;
        for(int i = 0; i < sizeA; i++) {
            X[i] = rand() % rangeOfFlow;
            if(i == k * NumberOfNodes + k) {
                //X[i] = 0;
                k++;
            }
        }
    }

    void genY() {
        for(int i = 0; i < sizeA; i++)
            for(int j = 0; j < sizeA; j++)
                Y[i] += G.A[i][j] * X[j];
    }

};


#endif