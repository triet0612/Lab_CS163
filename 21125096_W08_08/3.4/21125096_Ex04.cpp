#include "function.cpp"

int main() {
    int* arr;
    int size;
    loadArray("array.txt", arr, size);
    auto start = chrono::high_resolution_clock::now();
    insertionSort(arr, size);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    saveArray("output.txt", arr, size, duration.count());
    delete[]arr;
}
