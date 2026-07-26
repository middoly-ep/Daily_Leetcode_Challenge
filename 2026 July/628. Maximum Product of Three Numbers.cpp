#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size();
        int positive_product = nums[1] * nums[2];
        int negative_product = nums[n - 1] * nums[n - 2];
        if (nums[0] < 0) return nums[0] * nums[1] * nums[2];
        return nums[0] * max(negative_product, positive_product);
    }
};
