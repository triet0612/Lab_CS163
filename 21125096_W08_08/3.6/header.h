#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
using namespace std;

void loadArray(string filename, int* &arr, int &size);

void saveArray(string filename, int arr[], int size, long long runtime);

void mergeSort(int a[], int n);

void MergeRecur(int a[], int b[], int first, int last);

void Merge(int a[], int b[], int first, int last, int mid);
