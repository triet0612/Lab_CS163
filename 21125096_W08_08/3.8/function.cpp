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

void radixSort(int a[], int n) {
    int maxVal = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > maxVal) {
            maxVal = a[i];
        }
    }
    for (int e = 1; maxVal / e > 0; e *= 10) {
        countingSort(a, n, e);
    }
}

void countingSort(int a[], int n, int e) {
    int* b = new int[n];
    int i;
    int countArr[10];
    for (int i = 0; i < 10; i++) {
        countArr[i] = 0;
    }
    for (i = 0; i < n; i++) {
        countArr[(a[i] / e) % 10]++;
    }
    for (i = 1; i < 10; i++) {
        countArr[i] += countArr[i - 1];
    }
    for (i = n - 1; i >= 0; i--) {
        b[countArr[(a[i] / e) % 10] - 1] = a[i];
        countArr[(a[i] / e) % 10]--;
    }
    for (i = 0; i < n; i++) {
        a[i] = b[i];
    }
    delete[]b;
}
