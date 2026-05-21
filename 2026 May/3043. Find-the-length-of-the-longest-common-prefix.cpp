#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, bool> mp;
        int res = 0;
        for (int x : arr1){
            while (x > 0){
                mp[x] = true;
                x /= 10;
            }
        }
        for (int x : arr2){
            while (x > 0){
                if (mp[x]) res = max(res, x);
                x /= 10;
            }
        }

        int cnt = 0;
        while (res > 0){
            res /= 10;
            cnt++;
        }
        return cnt;
    }
};
