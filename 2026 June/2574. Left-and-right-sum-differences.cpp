#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        for (int i = 0; i < n; i++){
            if (i == 0){
                left[i] = nums[i];
                right[n - 1 - i] = nums[n - 1 - i];
            }
            else{
                left[i] = nums[i] + left[i - 1];
                right[n - 1 - i] = nums[n - 1 - i] + right[n - i];
            }
        }

        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++){
            ans[i] = abs(left[i] - right[i]);
        }
        return ans;
    }
};
