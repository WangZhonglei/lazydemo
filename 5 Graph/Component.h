//
// Created by liuyubobobo on 9/6/16.
//

#ifndef GRAPH_COMPONENT_H
#define GRAPH_COMPONENT_H

#include <iostream>
#include <cassert>
using namespace std;


template <typename Graph>
class Component{

private:
    Graph &G;
    bool* visited;
    int ccount = 0;  //记录连通分量数目
    int *id;  //对于第i个连通分量，其中的顶点放入id就是i

    void dfs( int v ){
        visited[v] = true;
        id[v] = ccount;
        typename Graph::adjIterator adj(G,v);  //typename表明adjIterator是一个类型，而不是成员变量
        for( int i = adj.begin() ; !adj.end() ; i = adj.next() )
            if( !visited[i] )
                dfs(i);

    }

public:
    Component(Graph &graph):G(graph){

        visited = new bool[G.V()];
        id = new int[G.V()];
        for( int i = 0 ; i < G.V() ; i ++ ){
            visited[i] = false;
            id[i] = -1;
        }
        ccount = 0;

        for( int i = 0 ; i < G.V() ; i ++ )
            if( !visited[i] ){
                dfs(i);
                ccount += 1;
            }
    }

    ~Component(){

        delete [] visited;
        delete [] id;
    }

    int count(){
        return ccount;
    }

    bool isConnected( int v , int w ){

        assert( v >= 0 && v < G.V() );
        assert( w >= 0 && w < G.V() );
        assert( id[v] != -1 && id[w] != -1 );
        return id[v] == id[w];
    }
};
#endif //GRAPH_COMPONENT_H
