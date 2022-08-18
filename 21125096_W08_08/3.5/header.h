#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
using namespace std;

void loadArray(string filename, int* &arr, int &size);

void saveArray(string filename, int arr[], int size, long long runtime);

void countingSort(int a[], int n);
