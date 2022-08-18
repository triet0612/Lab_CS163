#include "header.h"

void saveArray(string filename, int arr[], int size, long long runtime) {
    ofstream fout(filename);
    fout << "Runtime: " << runtime << endl;
    fout << "Size: " << size << endl;
    int i;
    for (i = 0; i < size; i++) {
        fout << arr[i] << " ";
    }
    fout.close();
}

void loadArray(string filename, int* &arr, int &size) {
    ifstream fin(filename);
    fin >> size;
    arr = new int[size];
    int i;
    for (i = 0; i < size; i++) {
        fin >> arr[i];
    }
    fin.close();
}

void mergeSort(int a[], int n) {
    int i;
    int* b = new int[n];
    for (i = 0; i < n; i++) {
        b[i] = a[i];
    }
    MergeRecur(b, a, 0, n);
    delete[]b;
}

void MergeRecur(int a[], int b[], int first, int last) {
    if (first >= last - 1) {
        return;
    }
    int mid = (last + first) / 2;
    MergeRecur(b, a, first, mid);
    MergeRecur(b, a, mid, last);
    Merge(a, b, first, last, mid);
}

void Merge(int a[], int b[], int first, int last, int mid) {
    int i = first;
    int j = mid;
    int k;
    for (k = first; k < last; k++) {
        if (i < mid && (j >= last || a[i] <= a[j])) {
            b[k] = a[i];
            i++;
        }
        else {
            b[k] = a[j];
            j++;
        }
    }
}
