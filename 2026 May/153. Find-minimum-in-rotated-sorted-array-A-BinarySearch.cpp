#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int res = INT_MAX;
        while (l <= r){
            int m = (l + r) / 2;
            res = min(res, nums[m]);
            if (nums[m] > nums[r]) l = m + 1;
            else r = m - 1;
        }
        return res;
    }
};
