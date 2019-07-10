#include"Header.h"
#include<iostream>

using namespace std;
int main() {
    Graph g = GraphGenerator(80);
    g.printAdjMatrix();
    g.createMatrixA();
    //g.printA();
}