#include <vector>
#include <string>
#include <utility

using namespace std;

class Solution {
public:
    pair<long long, long long> dp[17][11][11][2][2];
    string s;
    // dp[pos][last][second last][leading 0s][limit]

    pair<long long, long long> dfs(int pos, int last, int second_last, bool leading_zero, bool limit){
        if (dp[pos][last][second_last][leading_zero][limit] != make_pair(-1LL, -1LL)) {
            return dp[pos][last][second_last][leading_zero][limit];
        }
        if (pos == s.size()){
            return {1LL, 0LL};
        }

        int n = limit ? s[pos] - '0' : 9;
        long long total_ways = 0;
        long long total_waviness = 0;
        for (int i = 0; i <= n; i++){
            bool N_leading_zero = leading_zero && i == 0;
            bool N_limit = limit && i == s[pos] - '0';
            int N_last = N_leading_zero ? 10 : i;
            int N_second_last = N_leading_zero ? 10 : last;

            pair<long long, long long> ans = dfs(pos + 1, N_last, N_second_last, N_leading_zero, N_limit);
            long long ways = ans.first;
            long long waviness = ans.second;
            bool check = false;
            if (!leading_zero && last != 10 && second_last != 10){
                check = (last < i && last < second_last) || (last > i && last > second_last);
            }
            total_ways += ways;
            total_waviness += waviness + (ways * check);
        }
        return dp[pos][last][second_last][leading_zero][limit] = {total_ways, total_waviness};
    }

    long long solve(long long n){
        for (int i1 = 0; i1 < 17; i1++){
        for (int i2 = 0; i2 <= 10; i2++){
        for (int i3 = 0; i3 <= 10; i3++){
        for (int i4 = 0; i4 <= 1; i4++){
        for (int i5 = 0; i5 <= 1; i5++){
            dp[i1][i2][i3][i4][i5] = make_pair(-1LL, -1LL);
        }
        }
        }
        }
        }
        s = to_string(n);
        return dfs(0, 10, 10, 1, 1).second;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};
