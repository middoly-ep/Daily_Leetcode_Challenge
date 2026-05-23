#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++){
            if (nums[i + 1] < nums[i]) cnt++;
        }
        return cnt == 0 || (cnt == 1 && nums[0] >= nums[n - 1]);
    }
};#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++){
            if (nums[i + 1] < nums[i]) cnt++;
        }
        return cnt == 0 || (cnt == 1 && nums[0] >= nums[n - 1]);
    }
};
