#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mau = nums[0];
        int n = nums.size();
        vector<int> prefix(n, 0);
        prefix[0] = nums[0];

        for (int i = 1; i < n; i++){
            mau = max(mau, nums[i]);
            prefix[i] = gcd(nums[i], mau);
        }
        sort(prefix.begin(), prefix.end());

        long long s = 0;
        for (int i = 0; i < n / 2; i++){
            s += gcd(prefix[i], prefix[n - i - 1]);
        }
        return s;
    }
};
