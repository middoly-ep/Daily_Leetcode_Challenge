#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        while (n--){
            int tmp = nums[n];
            while (tmp > 0){
                res.push_back(tmp % 10);
                tmp /= 10;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
