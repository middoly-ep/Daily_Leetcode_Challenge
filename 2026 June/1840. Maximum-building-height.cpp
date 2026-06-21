#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    static bool cmp(vector<int> &v1, vector<int> &v2){
        return v1[0] < v2[0];
    }
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        sort(restrictions.begin(), restrictions.end(), cmp);
        if (restrictions.back()[0] != n) restrictions.push_back({n, n - 1});
        int m = restrictions.size();

        for (int i = 0; i < m - 1; i++) {
            int cur_id = restrictions[i][0], cur_h = restrictions[i][1];
            int nxt_id = restrictions[i + 1][0], nxt_h = restrictions[i + 1][1];
            
            restrictions[i + 1][1] = min(nxt_h, cur_h + (nxt_id - cur_id));
        }

        for (int i = m - 1; i > 0; i--) {
            int cur_id = restrictions[i][0], cur_h = restrictions[i][1];
            int prv_id = restrictions[i - 1][0], prv_h = restrictions[i - 1][1];
            
            restrictions[i - 1][1] = min(prv_h, cur_h + (cur_id - prv_id));
        }
        int res = 0;
        for (int i = 0; i < m - 1; i++){
            int a = restrictions[i][1];
            int b = restrictions[i+1][1];
            int dist = restrictions[i+1][0] - restrictions[i][0];
            int diff = abs(a - b);

            res = max(res, max(a, b) + (dist - diff) / 2);
        }

        return res;
    }
};
