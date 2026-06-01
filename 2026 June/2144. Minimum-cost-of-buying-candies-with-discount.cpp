#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        int s = 0;
        sort(cost.begin(), cost.end());
        for (int i = 0; i < n; i++){
            if ((n - i) % 3 != 0) s += cost[i];
        }
        return s;
    }
};
