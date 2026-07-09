#include <string>

using namespace std; 

class Solution {
public:
    long long sumAndMultiply(int n) {
        long long res = 0;
        long long sum = 0;
        string s = to_string(n);
        for (char x : s){
            sum += x - '0';
            if (x != '0') res = 10 * res + (x - '0');
        }
        return res * sum;
    }
};
