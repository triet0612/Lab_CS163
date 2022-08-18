#include "function.cpp"

int main(){
    int Arr[] = {12, 341, 231, 22, 665, 53};
    heapSort(Arr, 6);
    for (int i = 0; i < 6; i++){
        cout << Arr[i] << endl;
    }
}