#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long a = INT_MAX;
        long long b = INT_MIN;
        for (int x : nums){
            a = min(a, (long long)x);
            b = max(b, (long long)x);
        }
        return (b - a) * k;
    }
};
