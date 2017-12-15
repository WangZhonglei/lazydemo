//
// Created by liuyubobobo on 9/13/16.
//

#ifndef HEAP_MAXHEAP_H
#define HEAP_MAXHEAP_H

#include <algorithm>
#include <cassert>

using namespace std;


template<typename Item>
class MaxHeap{

private:
    Item *data;  //起初并不知道里面有多少元素，故用指针表示
    int count;  //堆里的元素数
    int capacity;  //insert()中count++可能越界，用此参数控制

    //将位置k处的元素向上移动
    void shiftUp(int k){
        while( k > 1 && data[k/2] < data[k] ){
            //此处可优化：将swap改进为赋值操作，把元素赋予它的最终位置
            swap( data[k/2], data[k] );
            k /= 2;
        }
    }
    //将位置k处的元素向下移动
    //先找出左右孩子的较大者，在与之比较
    void shiftDown(int k){
        //条件表示有左孩子
        while( 2*k <= count ){
            int j = 2*k;
            //判断是否有右孩子
            if( j+1 <= count && data[j+1] > data[j] )
                j ++;
            // data[j] 是 data[2*k]和data[2*k+1]中的最大值

            if( data[k] >= data[j] ) break;
            swap( data[k] , data[j] );
            k = j;
        }
    }

public:

    //开辟空间，索引是从1开始的，故而+1
    MaxHeap(int capacity){
        data = new Item[capacity+1];
        count = 0;
        this->capacity = capacity;
    }
    //用数组构造，heapify
    MaxHeap(Item arr[], int n){
        data = new Item[n+1];
        capacity = n;

        for( int i = 0 ; i < n ; i ++ )
            data[i+1] = arr[i];
        count = n;

        //从第一个非叶节点开始shiftDown
        for( int i = count/2 ; i >= 1 ; i -- )
            shiftDown(i);
    }

    ~MaxHeap(){
        delete[] data;
    }

    int size(){
        return count;
    }

    bool isEmpty(){
        return count == 0;
    }
    //如何向堆中添加元素
    void insert(Item item){
        assert( count + 1 <= capacity );  //判断若不满足，则开辟新空间（此处省略）
        data[count+1] = item;
        count ++;
        shiftUp(count);
    }
    //如何删除根节点
    Item extractMax(){
        assert( count > 0 );
        Item ret = data[1];
        swap( data[1] , data[count] );
        count --;
        shiftDown(1);
        return ret;
    }

    Item getMax(){
        assert( count > 0 );
        return data[1];
    }
};

#endif //HEAP_MAXHEAP_H
