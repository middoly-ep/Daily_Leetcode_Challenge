#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<pair<int, int>> sorted_arr;
        for (int i = 0; i < n; i++){
            sorted_arr.push_back(make_pair(arr[i], i));
        }
        sort(sorted_arr.begin(), sorted_arr.end());
        vector<int> dp(n, 1);

        for (auto p : sorted_arr){
            int val = p.first;
            int idx = p.second;
            for (int i = 1; i <= d; i++){
                if (idx - i >= 0 && arr[idx - i] < arr[idx]) dp[idx] = max(dp[idx], 1 + dp[idx - i]);
                else break;
            }
            for (int i = 1; i <= d; i++){
                if (idx + i < n && arr[idx + i] < arr[idx]) dp[idx] = max(dp[idx], 1 + dp[idx + i]);
                else break;
            }
        }

        int res = 0;
        for (int x : dp) res = max(res, x);
        return res;
    }
};
