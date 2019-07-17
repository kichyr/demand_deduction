#include"Header.h"
#include<iostream>
#include"simplex_kichyr.cpp"

using namespace std;

// C++ template to print vector container elements 

void addConstr(vector< vector<double> >& A, vector<double>& Y) {
    double sum_of_flows = 0;
    for(auto i : Y)
        sum_of_flows += i;
    double avg_val_of_flow = sum_of_flows / Y.size();
    
    vector<double> constrain = vector<double>(A[0].size(), 0);
    for(int i = 0; i < A[0].size(); i++) {
        constrain[i] = 1;
        A.push_back(constrain);
        constrain[i] = 0;
        Y.push_back(avg_val_of_flow * 1.4);
    }

}

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
    
    //addConstr(simulator.G.A, simulator.Y);
    cout << simulator.Y << endl;
    simulator.G.printA();
    Simplex simplex;
    cout << simulator.G.coeff;
    cout << simplex.do_Simplex(simulator.G.A, simulator.Y, simulator.G.coeff, 0);
}