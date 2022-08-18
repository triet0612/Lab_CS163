#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void checkMagazine(vector<string> magazine, vector<string> note) {
    unordered_map<string, int> checker1;
    for (auto i : magazine){
        checker1[i]++;
    }
    for (auto i : note){
        if (checker1[i] == 0){
            cout << "No" << endl;
            return;
        }
        checker1[i]--;
    }
    cout << "Yes" << endl;
}
