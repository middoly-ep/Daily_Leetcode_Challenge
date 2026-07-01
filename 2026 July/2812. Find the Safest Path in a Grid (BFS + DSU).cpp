#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    struct dsu {
        vector<int> parent;
        
        dsu(int size) {
            parent.resize(size);
            for(int i = 0; i < size; i++){
                parent[i] = i;
            }
        }

        int find(int x){
            return (x == parent[x]) ? x : parent[x] = find(parent[x]);
        }
        
        bool unite(int a, int b){
            int rootA = find(a);
            int rootB = find(b);
            if (rootA == rootB) return false;

            parent[rootB] = rootA;
            return true;
        }
    };

    bool isValid(int i, int j, vector<vector<bool>> &visited, int n){
        return i >= 0 && i < n && j >= 0 && j < n && !visited[i][j];
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return 0;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 1){
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        int curr = 0;
        while (!q.empty()){
            int sz = q.size();
            for (int i = 0; i < sz; i++){
                auto p = q.front();
                q.pop();
                grid[p.first][p.second] = curr;
                for (int d = 0; d < 4; d++){
                    int x = p.first + dx[d];
                    int y = p.second + dy[d];
                    if (isValid(x, y, visited, n)){
                        q.push({x, y});
                        visited[x][y] = true;
                    }
                }
            }
            curr++;
        }

        dsu d(n * n);

        vector<pair<int, int>> cells;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cells.push_back({i, j});
            }
        }

        sort(cells.begin(), cells.end(), [&](pair<int, int>& a, pair<int, int>& b) {
            return grid[a.first][a.second] > grid[b.first][b.second];
        });

        vector<vector<bool>> active(n, vector<bool>(n, false));

        for (auto& p : cells) {
            int r = p.first;
            int c = p.second;
            active[r][c] = true;

            for (int d_idx = 0; d_idx < 4; d_idx++) {
                int nr = r + dx[d_idx];
                int nc = c + dy[d_idx];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && active[nr][nc]) {
                    d.unite(r * n + c, nr * n + nc);
                }
            }

            if (active[0][0] && active[n-1][n-1]) {
                if (d.find(0) == d.find(n * n - 1)) {
                    return grid[r][c];
                }
            }
        }

        return 0;
    }
};
