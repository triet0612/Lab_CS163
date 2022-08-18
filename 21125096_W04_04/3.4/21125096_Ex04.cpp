#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        unordered_map<long long, long long> storage;
        int temp, x;
        cin >> x;
        long long ans = 0;
        for (int i = 0; i < x; i++){
            cin >> temp;
            ans += storage[temp-i];
            storage[temp-i]++;
        }
        cout << ans << endl;
    }
    return 0;
}