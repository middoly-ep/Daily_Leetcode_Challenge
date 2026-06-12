#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    const long long MOD = 1e9 + 7;
    unordered_map<int, vector<int>> neighbors;
    vector<int> depth;
    vector<vector<int>> up;
    int LOG;

    long long mu(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    void dfs(int u, int p, int d) {
        depth[u] = d;
        up[u][0] = p; 
        
        for (int j = 1; j < LOG; j++) {
            if (up[u][j - 1] != -1) {
                up[u][j] = up[up[u][j - 1]][j - 1];
            } else {
                up[u][j] = -1;
            }
        }
        
        for (int v : neighbors[u]) {
            if (v != p) {
                dfs(v, u, d + 1);
            }
        }
    }

    int getLCA(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        
        int diff = depth[u] - depth[v];
        for (int j = 0; j < LOG; j++) {
            if ((diff >> j) & 1) {
                u = up[u][j];
            }
        }
        
        if (u == v) return u;
        
        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != -1 && up[v][j] != -1 && up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }
        return up[u][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        neighbors.clear();
        int n = edges.size() + 1;
        LOG = ceil(log2(n)) + 1;
        
        for (auto v : edges) {
            neighbors[v[0]].push_back(v[1]);
            neighbors[v[1]].push_back(v[0]);
        }
        
        depth.assign(n + 1, 0);
        up.assign(n + 1, vector<int>(LOG, -1));
        dfs(1, -1, 0);

        vector<int> res;
        for (auto v : queries) {
            int u = v[0];
            int target = v[1];
            
            int lca = getLCA(u, target);
            int dist = depth[u] + depth[target] - 2 * depth[lca];
            
            if (dist == 0) {
                res.push_back(0);
            } else {
                res.push_back((int)mu(2, dist - 1));
            }
        }
        return res;
    }
};
