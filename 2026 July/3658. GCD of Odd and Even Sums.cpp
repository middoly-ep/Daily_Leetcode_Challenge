#include <numeric>

using namespace std; 

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return gcd((2*n)*n/2, (2*n+2)*n/2);
    }
};
