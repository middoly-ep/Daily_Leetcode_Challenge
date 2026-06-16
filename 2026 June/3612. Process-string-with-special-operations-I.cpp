#include <string>

using namespace std;

class Solution {
public:
    string processStr(string s) {
        string res;
        for (char x : s){
            if (x == '*'){
                if (res.size() > 0) res.pop_back();
            }
            else if (x == '#') res += res;
            else if (x == '%') reverse(res.begin(), res.end());
            else res += x;
        }
        return res;
    }
};
