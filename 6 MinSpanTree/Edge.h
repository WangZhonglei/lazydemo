//
// Created by liuyubobobo on 9/13/16.
//

#ifndef MINIMUMSPANTREE_EDGE_H
#define MINIMUMSPANTREE_EDGE_H

#include <iostream>

using namespace std;


template<typename Weight>
class Edge{
private:
    int a, b;  //两个顶点
    Weight weight;

public:
    Edge(int a, int b, Weight weight){
        this->a = a;
        this->b = b;
        this->weight = weight;
    }

    Edge(){}  //即可以用不带参数的类，方便后续使用

    ~Edge(){}

    int v(){ return a;}

    int w(){ return b;}

    Weight wt(){ return weight;}

    //返回边的另一个顶点
    int other(int x){
        assert( x == a || x == b );
        return x == a ? b : a;
    }

    bool operator<(Edge<Weight>& e){
        return weight < e.wt();
    }

    bool operator<=(Edge<Weight>& e){
        return weight <= e.wt();
    }

    bool operator>(Edge<Weight>& e){
        return weight > e.wt();
    }

    bool operator>=(Edge<Weight>& e){
        return weight >= e.wt();
    }

    bool operator==(Edge<Weight>& e){
        return weight == e.wt();
    }

    friend ostream& operator<<(ostream &os, const Edge &e){
        os<<e.a<<"-"<<e.b<<": "<<e.weight;
        return os;
    }
};

#endif //MINIMUMSPANTREE_EDGE_H