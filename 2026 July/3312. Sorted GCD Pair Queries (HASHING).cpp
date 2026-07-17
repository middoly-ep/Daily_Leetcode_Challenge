#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int max_val = 0;
        for (int x : nums) max_val = max(max_val, x);
        
        vector<long long> freq(max_val + 1, 0);
        for (int x : nums) freq[x]++;
        
        vector<long long> div(max_val + 1, 0);
        vector<long long> gcds(max_val + 1, 0);
        
        for (int i = 1; i <= max_val; i++){
            for (int j = i; j <= max_val; j += i){
                div[i] += freq[j];
            }
        }
        
        for (int i = max_val; i >= 1; i--){
            gcds[i] = div[i] * (div[i] - 1) / 2;
            for (int j = 2 * i; j <= max_val; j += i){
                gcds[i] -= gcds[j];
            }
        }
        
        for (int i = 1; i <= max_val; i++){
            gcds[i] += gcds[i - 1];
        }
        
        vector<int> res;
        for (auto x : queries){
            res.push_back(upper_bound(gcds.begin(), gcds.end(), x) - gcds.begin());
        }
        
        return res;
    }
};
