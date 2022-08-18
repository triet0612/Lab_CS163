#include <iostream>
#include <vector>
using namespace std;

vector<int> Max_Emerald(vector<vector<int>> v);

int Get_emerald(vector<int> ss);

int main(){
    int n;
    cin >> n;
    vector<vector<int>> v;
    int temp1, temp2;
    for (int i = 0; i < n; i++){
        cin >> temp1 >> temp2;
        v.push_back({temp1, temp2});
    }
    vector<int> ans = Max_Emerald(v);
    for (auto i : ans){
        cout << i << endl;
    }
    return 0;
}

vector<int> Max_Emerald(vector<vector<int>> v){
    vector<int> ans;
    for (auto i : v){
        ans.push_back(Get_emerald(i));
    }
    return ans;
}
//0: stick 1: diamond
int Get_emerald(vector<int> ss){
    int em = 0;
    int big = max(ss[0], ss[1]);
    int small = min(ss[0], ss[1]);
    if (small * 2 <= big){
        return small;
    } else {
        return (small + big)/3;
    }
}
