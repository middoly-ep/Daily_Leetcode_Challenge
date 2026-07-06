#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(int i, int j, int n){
        return i < n && j < n;
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const int MOD = 1e9 + 7;
        vector<int> di = {1, 1, 0};
        vector<int> dj = {0, 1, 1};

        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {0, 0}));
        // dp[i][j] = {max_points, ways}

        dp[n - 1][n - 1] = {0, 1};
        for (int k = 2 * n - 3; k >= 0; k--){
            int start_row = min(k, n - 1);
            int end_row = max(0, k - n + 1);
            for (int i = start_row; i >= end_row; i--){
                int j = k - i;
                if (board[i][j] == 'X'){
                    dp[i][j] = {0, 0};
                    continue;
                }
                long long ways = 0;
                int score = 0;
                for (int tmp = 0; tmp < 3; tmp++){
                    int ni = i + di[tmp];
                    int nj = j + dj[tmp];
                    if (isValid(ni, nj, n)){
                        if (dp[ni][nj].first == score) ways += dp[ni][nj].second;
                        else if (dp[ni][nj].first > score){
                            score = dp[ni][nj].first;
                            ways = dp[ni][nj].second;
                        }
                    }
                }
                ways %= MOD;
                if (board[i][j] != 'E') score += (board[i][j] - '0');
                dp[i][j] = {score, ways};
            }
        }
        if (dp[0][0].second == 0){
            return {0, 0};
        }
        return {dp[0][0].first, dp[0][0].second};
    }
};
