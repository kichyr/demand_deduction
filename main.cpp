#include"Header.h"
#include<iostream>
#include"simplex_kichyr.cpp"

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
    vector<double> coeff = vector<double>(simulator.sizeA, 1);
    simulator.G.printA();
    Simplex simplex;
    cout << simplex.do_Simplex( simulator.G.A, simulator.Y, coeff, 0);
}