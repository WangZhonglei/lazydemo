#include <iostream>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "BellmanFord.h"
#include "Dijkstra.h"

using namespace std;

int main() {

//    string filename = "testG1.txt";
    string filename = "testG2.txt";
//    string filename = "testG_negative_circle.txt";
    int V = 5;

    SparseGraph<int> g = SparseGraph<int>(V, true);
    ReadGraph<SparseGraph<int>, int> readGraph(g, filename);

    cout<<"Test Bellman-Ford:"<<endl<<endl;
    BellmanFord<SparseGraph<int>, int> bellmanFord(g,0);
    if( bellmanFord.negativeCycle() )
        cout<<"The graph contain negative cycle!"<<endl;
    else
        for( int i = 1 ; i < V ; i ++ ){
            cout<<"Shortest Path to "<<i<<" : "<<bellmanFord.shortestPathTo(i)<<endl;
            bellmanFord.showPath(i);
            cout<<"----------"<<endl;
        }
/*
    cout<<"Test Dijkstra:"<<endl<<endl;
    Dijkstra<SparseGraph<int>, int> dij(g,0);
    for( int i = 1 ; i < V ; i ++ ){
        cout<<"Shortest Path to "<<i<<" : "<<dij.shortestPathTo(i)<<endl;
        dij.showPath(i);
        cout<<"----------"<<endl;
    }
*/

    return 0;
}
