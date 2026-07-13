#include <vector>

using namespace std;

class Solution {
public:
    int seq(int digit, int sz){
        if (digit + sz > 10) return -1;
        int res = 0;
        while (sz--){
            res = 10*res + digit;
            digit++;
        }
        return res;
    }
    int digit_count(int x){
        int cnt = 0;
        while (x > 0){
            cnt++;
            x /= 10;
        }
        return cnt;
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        int start = digit_count(low);
        int end = digit_count(high);
        for (int sz = start; sz <= end; sz++){
        for (int d = 1; d <= 9; d++){
            int tmp = seq(d, sz);
            if (tmp >= low && tmp <= high) res.push_back(tmp);
        }
        }
        return res;
    }
};
