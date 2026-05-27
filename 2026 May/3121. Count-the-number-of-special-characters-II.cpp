#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        vector<bool> uppercase(26, false);
        vector<bool> lowercase(26, false);
        vector<bool> check(26, true);
        
        for (char x : word){
            if (x <= 'Z'){
                uppercase[x - 'A'] = true;
            }
            else{
                if (uppercase[x - 'a']) check[x - 'a'] = false;
                lowercase[x - 'a'] = true;
            }
        }

        int cnt = 0;
        for (int i = 0; i < 26; i++){
            cnt += lowercase[i] & uppercase[i] & check[i];
        }
        return cnt;
    }
};
