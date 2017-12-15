//
// Created by liuyubobobo on 9/13/16.
//

#ifndef MINIMUMSPANTREE_LAZYPRIMMST_H
#define MINIMUMSPANTREE_LAZYPRIMMST_H

#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.h"
#include "MinHeap.h"

using namespace std;

//时间复杂度是O(ElogE)，可优化为O(ElogV)
template<typename Graph, typename Weight>
class LazyPrimMST{

private:
    Graph &G;
    vector<Edge<Weight>> mst;  //存取树的n-1条边

    bool* marked;  //标记访问到的点
    MinHeap<Edge<Weight>> pq;
    Weight mstWeight;


    void visit(int v){
        //用邻接表遍历是O(E)
        assert( !marked[v] );
        marked[v] = true;

        typename Graph::adjIterator adj(G,v);
        for( Edge<Weight>* e = adj.begin() ; !adj.end() ; e = adj.next() )
            if( !marked[e->other(v)] )
                pq.insert(*e);  //O(logE)

    }
public:
    // 保证图是连通无向有权图
    LazyPrimMST(Graph &graph):G(graph), pq(MinHeap<Edge<Weight>>(graph.E())){

        marked = new bool[G.V()];
        for( int i = 0 ; i < G.V() ; i ++ )
            marked[i] = false;
        mst.clear();

        //Lazy Prim
        visit(0);
        while( !pq.isEmpty() ){
            //取出最小边，并判断是否为切边
            Edge<Weight> e = pq.extractMin();  //O(logE)
            if( marked[e.v()] && marked[e.w()] )
                continue;

            mst.push_back(e);
            //将该切边还没访问的端点，加入访问集合
            if( !marked[e.v()] )
                visit(e.v());
            if( !marked[e.w()] )
                visit(e.w());
        }

        mstWeight = mst[0].wt();
        for( int i = 1 ; i < mst.size() ; i ++ )
            mstWeight += mst[i].wt();
    }

    ~LazyPrimMST(){
        delete[] marked;
    }

    vector<Edge<Weight>> mstEdges(){
        return mst;
    };

    Weight result(){
        return mstWeight;
    };
};

#endif //MINIMUMSPANTREE_LAZYPRIMMST_H
