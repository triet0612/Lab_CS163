#include <unordered_map>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void whatFlavors(vector<int> cost, int money) {
    unordered_map<int, int> cost_flavor;
    for (int i = cost.size()-1; i >= 0; i--){
        cost_flavor[cost[i]] = i;
    }
    for (int i = 0; i < cost.size(); i++){
        int temp = money - cost[i];
        if (cost_flavor.find(temp) != cost_flavor.end() && cost_flavor[temp] != i){
            cout << min(i+1, cost_flavor[temp]+1) << " " << max(i+1, cost_flavor[temp]+1) << endl;
            return;
        }
    }
}