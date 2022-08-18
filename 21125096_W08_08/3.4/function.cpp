#include "header.h"

void insertionSort(int a[], int n) {
    int i, j, cur;
    for (i = 1; i < n; i++) {
        cur = a[i];
        for (j = i - 1; j >= 0 && a[j] > cur; j--)
            swap(a[j + 1], a[j]);
    }
}

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
