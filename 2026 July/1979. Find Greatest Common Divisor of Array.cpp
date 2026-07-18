#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int min_val = INT_MAX;
        int max_val = INT_MIN;
        for (int x : nums){
            min_val = min(min_val, x);
            max_val = max(max_val, x);
        }
        return gcd(min_val, max_val);
    }
};
