#include <vector>
 
using namespace std;

class Solution {
public:
    vector<int> parent;
    int find(int x){
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }
    void unite(int a, int b){
        int rootA = find(a);
        int rootB = find(b);
        parent[rootB] = rootA;
        return;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++){
            parent[i] = i;
        }
        for (auto v : roads){
            unite(v[0], v[1]);
        }
        int res = INT_MAX;
        for (auto v : roads){
            if (find(v[0]) == find(1)) res = min(res, v[2]);
        }
        return res;
    }
};
