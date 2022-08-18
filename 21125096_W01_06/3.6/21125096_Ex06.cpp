#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> Input_Dungeon(int n);
bool Check_Beautiful(vector<int> v);

int main(){
    int n;
    cin >> n;
    vector<vector<int>> v = Input_Dungeon(n);
    for (auto i : v){
        if(Check_Beautiful(i)){
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

vector<vector<int>> Input_Dungeon(int n){
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        vector<int> temp = {a, b, c};
        ans.push_back(temp);
    }
    return ans;
}

bool Check_Beautiful(vector<int> v){
    int a = (v[0] + v[1] + v[2]) / 9;
    int min_v = min(v[0], min(v[1], v[2]));
    return (a <= min_v) && ((v[0] + v[1] + v[2]) % 9 == 0);
}
