#include <iostream>
#include <algorithm>
#include <sorttesthelper.h>
#include <student.h>
#include<cmath>
#include<selectionsort.h>

using namespace std;


int main() {

/*    Student d[4] = {{"D",90},{"C",100},{"A",95},{"B",95}};
    int a[10] = {10,9,8,7,6,5,4,3,2,1};
    selectionSort(d,4);
    for( int i = 0 ; i < 4 ; i ++ )
       cout<<d[i]<<" ";
    cout<<endl;
*/
    int n = 10000;  //n扩大10倍，时间增长100倍，验证了时间复杂度
    int *arr = SortTestHelper::generateRandomArray( n , 0, n );
//    selectionSort( arr , n );
//    SortTestHelper::printArray(arr, n);

    SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
    delete[] arr; //清除generateRandomArray中开辟的内存

    return 0;
}
