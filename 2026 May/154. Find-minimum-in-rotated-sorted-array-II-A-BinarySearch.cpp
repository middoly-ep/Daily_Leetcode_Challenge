#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int bs(vector<int> &nums, int l, int r){
        int mid = (l + r) / 2;
        if (mid == l) return min(nums[l], nums[r]);
        if (nums[mid] > nums[r]){
            return min(nums[mid], bs(nums, mid + 1, r));
        }

        if (nums[mid] == nums[r]){
            if (nums[mid] != nums[l]) return min(nums[mid], bs(nums, l, mid - 1));
            return min(nums[mid], min(bs(nums, l, mid - 1), bs(nums, mid + 1, r)));
        }
        return min(nums[mid], bs(nums, l, mid - 1));
    }

    int findMin(vector<int>& nums) {
        int n = nums.size();
        return bs(nums, 0, n - 1);
    }
};
