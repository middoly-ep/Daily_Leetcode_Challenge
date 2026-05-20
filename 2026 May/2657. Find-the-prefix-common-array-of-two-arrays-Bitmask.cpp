#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int cnt = 0;
        int n = A.size();
        long long mask = 0;
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++){
            if ((mask & (1LL << A[i])) != 0) cnt++;
            else mask |= (1LL << A[i]);

            if ((mask & (1LL << B[i])) != 0) cnt++;
            else mask |= (1LL << B[i]);
            res[i] = cnt;
        }
        
        return res;
    }
};
