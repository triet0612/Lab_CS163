#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int Left = 0;
        int Right = nums.size() - 1;
        while (Left <= Right){
            int pos = floor((Left + Right) / 2);
            if (nums[pos] < target){
                Left = pos + 1;
            }
            else if (nums[pos] > target){
                Right = pos - 1;
            }
            else {
                return pos;
            }
        }
        return -1;
    }
};