#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.size() == 0) return {};
        int n = arr.size();
        vector<int> res(n, 0);
        vector<pair<int, int>> ranks(n);
        for (int i = 0; i < n; i++){
            ranks[i] = {arr[i], i};
        }
        sort(ranks.begin(), ranks.end());
        int curr = ranks[0].first;
        int curr_rank = 1;
        res[ranks[0].second] = 1;
        for (int i = 1; i < n; i++){
            if (ranks[i].first > curr){
                curr = ranks[i].first;
                curr_rank++;
            }
            res[ranks[i].second] = curr_rank;
        }
        return res;
    }
};
