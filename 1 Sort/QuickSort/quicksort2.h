#ifndef QUICKSORT2_H
#define QUICKSORT2_H


// 对arr[l...r]部分进行partition操作
// 返回p,使得arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]

template <typename T>
int __partition2(T arr[], int l, int r){

    swap( arr[l] , arr[rand()%(r-l+1)+l] );
    T v = arr[l];

    // arr[l+1...i) <= v; arr(j...r] >= v
    int i = l+1, j = r;
    while( true ){
        while( i <= r && arr[i] < v )
            i ++;

        while( j >= l+1 && arr[j] > v )
            j --;

        if( i > j )
            break;

        swap( arr[i] , arr[j] );
        i ++;
        j --;
    }

    swap( arr[l] , arr[j]);

    return j;
}

// 对arr[l...r]部分进行快速排序
template <typename T>
void __quickSort2(T arr[], int l, int r){

//  if( l >= r )
//      return;
    //优化1，小数组改用插入排序
    if( r - l <= 15 ){
        insertionSort(arr,l,r);
            return;
    }

    int p = __partition2(arr, l, r);
    __quickSort2(arr, l, p-1 );
    __quickSort2(arr, p+1, r);
}

template <typename T>
void quickSort2(T arr[], int n){

    srand(time(NULL));
    __quickSort2(arr, 0, n-1);
}

#endif // QUICKSORT2_H
