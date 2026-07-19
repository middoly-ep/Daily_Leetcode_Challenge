#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        vector<int> suf(n + 1, 0);
        
        for (int i = n - 1; i >= 0; i--){
            suf[i] = suf[i + 1] | (1 << (s[i] - 'a'));
        }
        
        int target_mask = suf[0];
        int picked_mask = 0;
        string res = "";
        int last_pos = -1;
        
        int total_chars = 0;
        for (int i = 0; i < 26; i++){
            if ((target_mask >> i) & 1) total_chars++;
        }
        
        for (int step = 0; step < total_chars; step++){
            for (int i = 0; i < 26; i++){
                if ((picked_mask >> i) & 1) continue;
                
                int pos = -1;
                for (int j = last_pos + 1; j < n; j++){
                    if (s[j] - 'a' == i){
                        pos = j;
                        break;
                    }
                }
                
                if (pos == -1) continue;
                
                int remaining = target_mask ^ (picked_mask | (1 << i));
                if ((suf[pos] & remaining) == remaining){
                    res += (char)(i + 'a');
                    picked_mask |= (1 << i);
                    last_pos = pos;
                    break;
                }
            }
        }
        
        return res;
    }
};
