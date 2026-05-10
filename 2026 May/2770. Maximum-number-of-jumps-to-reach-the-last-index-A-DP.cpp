#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    bool valid_jump(int i, int j, vector<int> &nums, int target){
        return (i < j) && (abs(nums[i] - nums[j]) <= target);
    }

    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = 0;
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                if (dp[i] != -1 && valid_jump(i, j, nums, target)) dp[j] = max(dp[j], dp[i] + 1); 
            }
        }
        return dp[n - 1];
    }
};
