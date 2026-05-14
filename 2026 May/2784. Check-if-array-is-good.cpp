#include <vector>

using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n, 0);
        for (int x : nums){
            if (x >= n) return false;
            if (x != n - 1 && freq[x] > 0) return false;
            freq[x]++;
        }
        return freq[n - 1] == 2;
    }
};
