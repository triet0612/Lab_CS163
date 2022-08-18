#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <map>
using namespace std;

void loadArray(string filename, int* &arr, int &size);

void saveArray(string filename, int arr[], int size, long long runtime);

void radixSort(int a[], int n);

void countingSort(int a[], int n, int e);
