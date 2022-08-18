#include "header.h"

//return index, -1 <> no 
int parent(int a[], int n, int i){
    return (i == 0) * (-1) + (i != 0) * ((i-1)/2);
}

int left(int a[], int n, int i){
    return (2*i + 1); 
}

int right(int a[], int n, int i){
    return (2*i + 2);
}

void maxHeapify(int a[], int n, int i){
    int pLeft = left(a, n, i);
    int pRight = right(a, n, i);
    int max = i;
    if (pLeft < n && a[pLeft] > a[max]){
        max = pLeft;
    }
    if (pRight < n && a[pRight] > a[max]){
        max = pRight;
    }
    if (max != i){
        swap(a[i], a[max]);
        maxHeapify(a, n, max);
    }
}

void buildMaxHeap(int a[], int n){
    for (int i = (n/2)-1; i >= 0; i--){
        maxHeapify(a, n, i);
    }
}

void heapSort(int a[], int n){
    buildMaxHeap(a, n);
    for (int i = n-1; i >= 0; i--){
        swap(a[0], a[i]);
        maxHeapify(a, i, 0);
    }
}