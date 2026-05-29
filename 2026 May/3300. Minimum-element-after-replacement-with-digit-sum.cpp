#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int digit_sum(int x){
        int res = 0;
        while (x > 0){
            res += x % 10;
            x /= 10;
        }
        return res;
    }
    int minElement(vector<int>& nums) {
        int res = INT_MAX;
        for (int x : nums){
            res = min(res, digit_sum(x));
        }
        return res;
    }
};
