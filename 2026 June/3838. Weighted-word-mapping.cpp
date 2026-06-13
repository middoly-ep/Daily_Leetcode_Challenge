#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res = "";
        for (string s : words){
            int val = 0;
            for (char x : s) val += weights[x - 'a'];
            res += ('z' - (val % 26));
        }
        return res;
    }
};
