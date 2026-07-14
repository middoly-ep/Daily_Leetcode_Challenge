#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        const int MOD = 1e9+7;
        int n = nums.size();
        if (n == 1) return 0;
        vector<vector<int>> dp(201, vector<int>(201, 0));
        //dp[g1][g2] = ways
        dp[0][0] = 1;
        vector<vector<int>> next_dp;

        for (int i = 0; i < n; i++){
            next_dp = dp;
            for (int d1 = 0; d1 <= 200; d1++){
            for (int d2 = 0; d2 <= 200; d2++){
                if (dp[d1][d2] > 0){
                    int n_d1 = gcd(d1, nums[i]);
                    int n_d2 = gcd(d2, nums[i]);
                    next_dp[n_d1][d2] += dp[d1][d2];
                    next_dp[n_d1][d2] %= MOD;
                    next_dp[d1][n_d2] += dp[d1][d2];
                    next_dp[d1][n_d2] %= MOD;
                }
            }
            }
            dp = next_dp;
        }
        int res = 0;
        for (int i = 1; i <= 200; i++){
            res += dp[i][i];
            res %= MOD;
        }
        return res;
    }
};
