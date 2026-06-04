#include <string>

using namespace std;

class Solution {
public:
    int count_waviness(int n){
        string s = to_string(n);
        int cnt = 0;
        for (int i = 1; i <  s.size() - 1; i++){
            cnt += (s[i] - '0' >  s[i - 1] - '0' && s[i] - '0' > s[i + 1] - '0') || (s[i] - '0' < s[i - 1] - '0' && s[i] - '0' < s[i + 1] - '0');
        }
        return cnt;
    }
    int totalWaviness(int num1, int num2) {
        int res = 0;
        for (int n = num1; n <= num2; n++){
            res += count_waviness(n);
        }
        return res;
    }
};
