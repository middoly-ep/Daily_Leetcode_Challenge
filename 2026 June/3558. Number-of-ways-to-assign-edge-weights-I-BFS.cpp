#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    const long long MOD = 1e9 + 7LL;
    
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> neighbor;
        unordered_map<int, bool> visited;
        
        for (auto& v : edges) {
            neighbor[v[0]].push_back(v[1]);
            neighbor[v[1]].push_back(v[0]);
        }

        int level = 0;
        queue<int> q;
        q.push(1);
        visited[1] = true;
        
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int val = q.front();
                q.pop();
                for (int x : neighbor[val]) {
                    if (!visited[x]) {
                        q.push(x);
                        visited[x] = true;
                    }
                }
            }
            level++;
        }
        
        long long ans = (power(2, level - 2) + MOD) % MOD;
        return ans;
    }
};
