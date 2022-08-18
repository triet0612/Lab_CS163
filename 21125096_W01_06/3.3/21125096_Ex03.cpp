#include <iostream>
using namespace std;

int Get_time(int _num_of_tests, int _test_time);

int main(){
    int _num_of_tests;
    int _travel_time;
    cin >> _num_of_tests >> _travel_time;
    int _test_time = 240 - _travel_time;
    cout << Get_time(_num_of_tests, _test_time) << endl;
}

int Get_time(int _num_of_tests, int _test_time){
    int time = 0;
    int ans = 0;
    for (int i = 1; i <= _num_of_tests; i++){
        time += i*5;
        if (time > _test_time){
            break;
        }
        ans = i;
    }
    return ans;
}
