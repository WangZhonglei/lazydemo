#include <iostream>
#include <algorithm>
#include <ctime>
#include "Heap.h"
#include "heapsort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "SortTestHelper.h"
#include "quicksort3ways.h"

using namespace std;

int main() {

    int n = 300000;

    // 测试1 一般性测试
    cout<<"Test for Random Array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);
    int* arr3 = SortTestHelper::copyIntArray(arr1, n);
    int* arr4 = SortTestHelper::copyIntArray(arr1, n);
    int* arr5 = SortTestHelper::copyIntArray(arr1, n);
    int* arr6 = SortTestHelper::copyIntArray(arr1, n);


    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr3, n);
    SortTestHelper::testSort("Heap Sort 1", heapSort1, arr4, n);
    SortTestHelper::testSort("Heap Sort 2", heapSort2, arr5, n);
    SortTestHelper::testSort("Heap Sort", heapSort, arr6, n);


    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;

    cout<<endl;


    // 测试2 测试近乎有序的数组
    int swapTimes = 100;
    cout<<"Test for Random Nearly Ordered Array, size = "<<n<<", swap time = "<<swapTimes<<endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    arr4 = SortTestHelper::copyIntArray(arr1, n);
    arr5 = SortTestHelper::copyIntArray(arr1, n);
    arr6 = SortTestHelper::copyIntArray(arr1, n);


    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr3, n);
    SortTestHelper::testSort("Heap Sort 1", heapSort1, arr4, n);
    SortTestHelper::testSort("Heap Sort 2", heapSort2, arr5, n);
    SortTestHelper::testSort("Heap Sort", heapSort, arr6, n);


    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;


    cout<<endl;


    // 测试3 测试存在包含大量相同元素的数组
    cout<<"Test for Random Array, size = "<<n<<", random range [0,10]"<<endl;
    arr1 = SortTestHelper::generateRandomArray(n,0,10);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    arr4 = SortTestHelper::copyIntArray(arr1, n);
    arr5 = SortTestHelper::copyIntArray(arr1, n);
    arr6 = SortTestHelper::copyIntArray(arr1, n);


    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr3, n);
    SortTestHelper::testSort("Heap Sort 1", heapSort1, arr4, n);
    SortTestHelper::testSort("Heap Sort 2", heapSort2, arr5, n);
    SortTestHelper::testSort("Heap Sort", heapSort, arr6, n);


    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;

    return 0;
}
