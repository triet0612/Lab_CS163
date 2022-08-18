#include <vector>
using namespace std;

class MyHashSet {
public:
    int size;
    vector<vector<int>> data;
    MyHashSet() {
        size = 2000003;
        data = vector<vector<int>>(2000003, vector<int> {});
    }
    
    void add(int key) {
        int hash = key % 2000003;
        for (auto i : data[hash]){
            if (i == key){
                return;
            }
        }
        data[hash].push_back(key);
    }
    
    void remove(int key) {
        int hash = key % 2000003;
        for (int i = 0; i < data[hash].size(); i++){
            if (data[hash][i] == key){
                data[hash].erase(data[hash].begin() + i);
            }
        }
        return;
    }
    
    bool contains(int key) {
        int hash = key % 2000003;
        for (auto i : data[hash]){
            if (i == key){
                return true;
            }
        }
        return false;
    }
};
