#include"Header.h"
#include<iostream>
#include"Simplex.cpp"

using namespace std;

// C++ template to print vector container elements 
template <typename T> 
ostream& operator<<(ostream& os, const vector<T>& v) 
{ 
    os << "["; 
    for (int i = 0; i < v.size(); ++i) { 
        os << v[i]; 
        if (i != v.size() - 1) 
            os << ", "; 
    } 
    os << "]\n"; 
    return os; 
} 

int main() {
    SimulatorTask simulator;
    simulator.generateInstanceOfTask(4, 10, true);
    //g.printA();
    vector<float> coeff = vector<float>(simulator.sizeA, 100);
    simulator.G.printA();
    vector<vector<float>> A = simulator.G.A;
    Simplex simplex(A, coeff, coeff);
    simplex.CalculateSimplex();
}