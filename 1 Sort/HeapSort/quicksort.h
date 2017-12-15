#ifndef QUICKSORT_H
#define QUICKSORT_H


// 对arr[l...r]部分进行partition操作
// 返回p,使得arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
template <typename T>
int __partition(T arr[], int l, int r){

    swap( arr[l] , arr[rand()%(r-l+1)+l] );

    T v = arr[l];
    //j的初始值保证左边数组初始为空，然后i的初始值保证右边数组初始为空
/*    int j = l; // arr[l+1...j] < v ; arr[j+1...i) > v;
    for( int i = l + 1 ; i <= r ; i ++ )
        if( arr[i] < v ){
            j ++;
            swap( arr[j] , arr[i] );
        }
*/

    //保证生成树相对平衡，故处理情形3，较上面注释的部分效率高
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

    //最后把v放中间
    swap( arr[l] , arr[j]);

    return j;
}

// 对arr[l...r]部分进行快速排序
template <typename T>
void __quickSort(T arr[], int l, int r){

//  if( l >= r )
//      return;
    //优化1，小数组改用插入排序
    if( r - l <= 15 ){
        insertionSort(arr,l,r);
            return;
    }

    int p = __partition(arr, l, r);
    __quickSort(arr, l, p-1 );
    __quickSort(arr, p+1, r);
}

template <typename T>
void quickSort(T arr[], int n){

    srand(time(NULL));
    __quickSort(arr, 0, n-1);
}

#endif // QUICKSORT_H
