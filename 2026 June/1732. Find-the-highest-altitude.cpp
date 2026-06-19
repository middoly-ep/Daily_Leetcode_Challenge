#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0;
        int curr = 0;
        for (int x : gain){
            curr += x;
            res = max(res, curr);
        }
        return res;
    }
};
