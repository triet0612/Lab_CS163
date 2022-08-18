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

void countingSort(int a[], int n) {
    int* sorted = new int[n];
    int minval = a[0];
    int maxval = a[0];
    int i;
    for (i = 1; i < n; i++) {
        if (a[i] > maxval)
            maxval = a[i];
        if (a[i] < minval)
            minval = a[i];
    }
    int range = maxval - minval + 1;
    int* countArr = new int[range];
    for (i = 0; i < range; i++) {
        countArr[i] = 0;
    }
    for (i = 0; i < n; i++)
        countArr[a[i] - minval]++;
    for (i = 1; i < range; i++) {
        countArr[i] += countArr[i - 1];
    }
    for (i = 0; i < n; i++) {
        sorted[countArr[a[i] - minval] - 1] = a[i];
        countArr[a[i] - minval]--;
    }
    for (i = 0; i < n; i++) {
        a[i] = sorted[i];
    }
    delete[]sorted;
    delete[]countArr;
}
