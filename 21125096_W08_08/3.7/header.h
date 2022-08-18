#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <map>
using namespace std;

void loadArray(string filename, int* &arr, int &size);

void saveArray(string filename, int arr[], int size, long long runtime);

void quickSort(int a[], int right, int left);

int partition(int a[], int right, int left);
