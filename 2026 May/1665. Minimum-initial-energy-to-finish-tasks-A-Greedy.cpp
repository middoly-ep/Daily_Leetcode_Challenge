#include <algorithm>
#include <vector>

using namespace std; 

class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        return (a[1] - a[0]) < (b[1] - b[0]);
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), cmp);
        int res = 0;
        for (auto v : tasks){
            res = max(res + v[0], v[1]);
        }
        return res;
    }
};
