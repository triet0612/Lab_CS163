#include "header.h"

int GetMin(int a[], int n, int curPos) {
    int i;
    int curMin = a[curPos + 1];
    int minPos = curPos + 1;
    for (i = curPos + 1; i < n; i++) {
        if (curMin > a[i]) {
            curMin = a[i];
            minPos = i;
        }
    }
    return minPos;
}

void selectionSort(int a[], int n) {
    int i;
    int posMin;
    for (i = 0; i < n - 1; i++) {
        posMin = GetMin(a, n, i);
        if (a[posMin] < a[i])
            swap(a[posMin], a[i]);
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
