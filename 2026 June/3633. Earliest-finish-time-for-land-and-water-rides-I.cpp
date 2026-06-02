#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int res = INT_MAX;
        int end = INT_MAX;
        int land = landStartTime.size();
        int water = waterStartTime.size();
        for (int i = 0; i < land; i++){
            end = min(end, landStartTime[i] + landDuration[i]);
        }
        for (int i = 0; i < water; i++){
            res = min(res, max(end, waterStartTime[i]) + waterDuration[i]);
        }
        end = INT_MAX;
        for (int i = 0; i < water; i++){
            end = min(end, waterStartTime[i] + waterDuration[i]);
        }
        for (int i = 0; i < land; i++){
            res = min(res, max(end, landStartTime[i]) + landDuration[i]);
        }
        return res;
    }
};
