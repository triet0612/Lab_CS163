#include <iostream>
#include <vector>
using namespace std;

vector<int> Input_Sushi();

int Solve_Big_Sushi(vector<int> v);

int main(){
    vector<int> input = Input_Sushi();
    cout << Solve_Big_Sushi(input);
    return 0;
}

vector<int> Input_Sushi(){
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    return v;
}

int Solve_Big_Sushi(vector<int> v){
    vector<vector<int>> a;
    vector<int> temp = {v[0]};
    for (int i = 1; i < v.size(); i++){
        if (v[i] == v[i-1]){
            temp.push_back(v[i]);
        }
        else {
            a.push_back(temp);
            temp = {v[i]};
        }
    }
    a.push_back(temp);
    int Max_len = 0;
    for (int i = 1; i < a.size(); i++){
        int t = min(a[i].size(), a[i-1].size()) * 2;
        Max_len = max(Max_len, t);
    }
    return Max_len;
}
