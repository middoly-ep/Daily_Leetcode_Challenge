#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> lowercase(26, false);
        vector<bool> uppercase(26, false);
        for (char x : word){
            if (x <= 'Z') uppercase[x - 'A'] = true;
            else lowercase[x - 'a'] = true;
        }
        int cnt = 0;
        for (int i = 0; i < 26; i++){
            cnt += lowercase[i] & uppercase[i];
        }
        return cnt;
    }
};
