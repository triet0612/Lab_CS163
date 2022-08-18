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

void quickSort(int a[], int right, int left) {
    if (left < right){
        int pivot = partition(a, right, left);
        quickSort(a, pivot - 1, left);
        quickSort(a, right, pivot + 1);
    }
}

int partition(int a[], int right, int left) {
    int pivot = a[right];
    int temp = left - 1;
    for (int i = left; i < right; i++) {
        if (a[i] <= pivot) {
            temp++;
            swap(a[i], a[temp]);
        }
    }
    swap(a[right], a[temp + 1]);
    return temp + 1;
}
