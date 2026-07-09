#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        int n = s.size();

        vector<int> sums(n + 1, 0);
        vector<int> cnt(n + 1, 0);
        vector<int> nums(n + 1, 0);
        vector<int> exp(n + 1, 0);

        exp[0] = 1;
        for (int i = 1; i <= n; i++) {
            exp[i] = (1LL * exp[i - 1] * 10) % MOD;
        }

        for (int i = 1; i <= n; i++) {
            char c = s[i - 1];
            sums[i] = sums[i - 1] + (c - '0');
            
            if (c == '0') {
                cnt[i] = cnt[i - 1];
                nums[i] = nums[i - 1];
            } else {
                cnt[i] = cnt[i - 1] + 1;
                nums[i] = (1LL * nums[i - 1] * 10 + (c - '0')) % MOD;
            }
        }

        vector<int> res;
        for (auto& v : queries) {
            int L = v[0] + 1;
            int R = v[1] + 1;

            int k = cnt[R] - cnt[L - 1];

            long long X = (nums[R] - (1LL * nums[L - 1] * exp[k]) % MOD + MOD) % MOD;

            long long S = sums[R] - sums[L - 1];

            long long ans = (X * S) % MOD;
            res.push_back(ans);
        }

        return res;
    }
};
