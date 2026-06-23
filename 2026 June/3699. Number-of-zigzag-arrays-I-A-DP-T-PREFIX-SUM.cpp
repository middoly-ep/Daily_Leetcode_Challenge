#include <vector>

using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    int zigZagArrays(int n, int l, int r) {
        if (n == 1) return r - l + 1;
        vector<int> i_dp(r + 1, 1);
        vector<int> d_dp(r + 1, 1);
        vector<int> i_next_dp(r + 1, 0);
        vector<int> d_next_dp(r + 1, 0);
        for (int i = 2; i <= n; i++){
            int i_sum = 0;
            int d_sum = 0;

            for (int digit = l; digit <= r; digit++){
                i_next_dp[digit] = i_sum;
                i_sum += d_dp[digit];
                i_sum %= MOD;
            }
            for (int digit = r; digit >= l; digit--){
                d_next_dp[digit] = d_sum;
                d_sum += i_dp[digit];
                d_sum %= MOD;
            }
            i_dp = i_next_dp;
            d_dp = d_next_dp;
        }
        int res = 0;
        for (int digit = l; digit <= r; digit++){
            res += i_dp[digit];
            res %= MOD;
            res += d_dp[digit];
            res %= MOD;
        }
        return res;
    }
};
