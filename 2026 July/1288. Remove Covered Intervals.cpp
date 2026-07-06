#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        if (a[0] != b[0]) return a[0] < b[0];
        return a[1] > b[1];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int r = 0;
        int cnt = 0;
        for (auto v : intervals){
            if (v[1] > r){
                r = v[1];
                cnt++;
            }
        }
        return cnt;
    }
};
