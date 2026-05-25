#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<bool> reachable(n, false);
        reachable[0] = true;
        int l = -1;
        int r = -1;
        int cnt = 0;
        for (int i = 1; i < n; i++){
            if (l < i - maxJump){
                if (l >= 0 && reachable[l] && s[l] == '0') cnt--;
                l++;
            }
            if (r < i - minJump){
                r++;
                if (reachable[r] && s[r] == '0') cnt++;   
            }
            if (cnt > 0 && s[i] == '0') reachable[i] = true;
        }
        return reachable[n - 1];
    }
};
