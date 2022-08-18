#include <math.h>
class MyHashSet {
public:
    int arr[2000003];
    int size;
    MyHashSet() {
        size = 2000003;
        for (int i = 0; i < 2000003; i++){
            arr[i] = -1;
        }
    }
    
    void add(int key) {
        int hash = key % size;
        if (arr[hash] == key){
            return;
        }
        if (arr[hash] == -1){
            arr[hash] = key;
            return;
        }
        while (arr[hash] != -1 && arr[hash] != key){
            hash++;
            if (hash > size){
                hash = 0;
            }
            if (arr[hash] == key){
                return;
            }
            if (arr[hash] == -1){
                break;
            }
        }
        if (arr[hash] == -1){
            arr[hash] = key;
        }
    }
    
    void remove(int key) {
        int hash = key % size;
        int index = binarySearch(arr, hash, size-1, key);
        if (index != -1){
            arr[index] = -1;
            return;
        }
        else {
            index = binarySearch(arr, 0, hash, key);
            if (index != -1){
                arr[index] = -1;
            }
        }
        return;
    }
    
    bool contains(int key) {
        int hash = key % size;
        int index = binarySearch(arr, hash, size-1, key);
        if (index != -1){
            return true;
        }
        else {
            index = binarySearch(arr, 0, hash, key);
            if (index != -1){
                return true;
            }
        }
        return false;
    }
    int binarySearch(int arr[], int left, int right, int x){
        while (left <= right){
            int mid = floor((left + right)/2);
            if (arr[mid] < x){
                left = mid+1;
            }
            else if (arr[mid] > x){
                right = mid-1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }
};
