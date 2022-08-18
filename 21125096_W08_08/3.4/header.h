#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
using namespace std;

void loadArray(string filename, int* &arr, int &size);

void insertionSort(int a[], int n);

void saveArray(string filename, int arr[], int size, long long runtime);
