//
// Created by liuyubobobo on 9/6/16.
//

#ifndef GRAPH_SPARSEGRAPH_H
#define GRAPH_SPARSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


// 稀疏图 - 邻接表
class SparseGraph{

private:
    int n, m;
    bool directed;
    vector<vector<int>> g;
public:
    SparseGraph( int n , bool directed){
        this->n = n;
        this->m = 0;
        this->directed = directed;
        for( int i = 0 ; i < n ; i ++ )
            g.push_back( vector<int>() );  //存放的是顶点号
    }

    ~SparseGraph(){

    }

    int V(){ return n;}
    int E(){ return m;}

    void addEdge( int v, int w ){
        assert( v >= 0 && v < n );
        assert( w >= 0 && w < n );

        g[v].push_back(w);
        if( v != w && !directed )
            g[w].push_back(v);
        m ++;
    }

    //if条件的判断，使得最差情况下，时间复杂度为O(n)
    //所以用邻接表取消平行边的成本较高
    bool hasEdge( int v , int w ){
        assert( v >= 0 && v < n );
        assert( w >= 0 && w < n );
        for( int i = 0 ; i < g[v].size() ; i ++ )
            if( g[v][i] == w )
                return true;
        return false;
    }

    void show(){

        for( int i = 0 ; i < n ; i ++ ){
            cout<<"vertex "<<i<<":\t";
            for( int j = 0 ; j < g[i].size() ; j ++ )
                cout<<g[i][j]<<"\t";
            cout<<endl;
        }
    }

    //邻边迭代器类
    class adjIterator{
    private:
        SparseGraph &G;
        int v;
        int index;  //记录当前迭代的位置
    public:
        adjIterator(SparseGraph &graph, int v): G(graph){
            this->v = v;
            this->index = 0;
        }

        int begin(){
            index = 0;
            if( G.g[v].size() )
                return G.g[v][index];
            return -1;
        }

        int next(){
            index += 1;
            if( index < G.g[v].size() )
                return G.g[v][index];
            return -1;
        }

        bool end(){
            return index >= G.g[v].size();
        }
    };
};

#endif //GRAPH_SPARSEGRAPH_H
