//
// Created by liuyubobobo on 9/11/16.
//

#ifndef GRAPH_PATH_H
#define GRAPH_PATH_H


#include <vector>
#include <stack>
#include <iostream>
#include <cassert>

using namespace std;


template <typename Graph>
class Path{

private:
    Graph &G;
    int s;  //源点
    bool* visited;
    int * from;  //记录前一个节点

    void dfs(int v){

        //遍历v的相邻节点，一旦发现没有被访问，就开始遍历新的点，往深里走
        visited[v] = true;
        typename Graph::adjIterator adj(G,v);
        for( int i = adj.begin() ; !adj.end() ; i = adj.next() )
            if( !visited[i] ){
                from[i] = v;  //只有源节点没有更新from的值，即为-1
                dfs(i);
            }
    }

public:
    Path(Graph &graph, int s):G(graph){

        // 算法初始化
        assert( s >= 0 && s < G.V() );

        visited = new bool[G.V()];
        from = new int[G.V()];
        for( int i = 0 ; i < G.V() ; i ++ ){
            visited[i] = false;
            from[i] = -1;
        }
        this->s = s;

        // 寻路算法
        dfs(s);
    }

    ~Path(){

        delete [] visited;
        delete [] from;
    }

    //判断源点s到w是否有路
    bool hasPath(int w){
        assert( w >= 0 && w < G.V() );
        return visited[w];
    }

    //给出源点s到w的路径
    void path(int w, vector<int> &vec){

        assert( w >= 0 && w < G.V() );

        stack<int> s;  //后进先出，为了下面的倒推过程

        //从w倒推
        int p = w;
        while( p != -1 ){
            s.push(p);
            p = from[p];
        }

        vec.clear();
        while( !s.empty() ){
            vec.push_back( s.top() );
            s.pop();
        }
    }

    void showPath(int w){

        assert( w >= 0 && w < G.V() );

        vector<int> vec;
        path(w, vec);
        for( int i = 0 ; i < vec.size() ; i ++ ){
            cout<<vec[i];
            if( i == vec.size()-1 )
                cout<<endl;
            else
                cout<<" -> ";
        }
    }
};

#endif //GRAPH_PATH_H
