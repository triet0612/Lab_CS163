#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int Left = 0;
        int Right = nums.size() - 1;
        if (target > nums[Right]){
            return Right+1;
        }
        else if (target < nums[Left]){
            return Left;
        }
        while (Left <= Right){
            int pos = floor((Left + Right) / 2);
            if (nums[pos] > target && nums[pos-1] < target){
                return pos;
            }
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