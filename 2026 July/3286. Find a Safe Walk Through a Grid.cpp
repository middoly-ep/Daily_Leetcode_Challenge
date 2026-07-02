#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(int x, int y, int m, int n){
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> dq;
        dq.push_back({0, 0});
        dist[0][0] = grid[0][0];
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        while (!dq.empty()){
            auto p = dq.front();
            dq.pop_front();
            if (p.first == m - 1 && p.second == n - 1){
                return dist[p.first][p.second] < health;
            }

            for (int i = 0; i < 4; i++){
                int ni = p.first + dx[i];
                int nj = p.second + dy[i];
                if (isValid(ni, nj, m, n) && dist[ni][nj] > dist[p.first][p.second] + grid[ni][nj]){
                    dist[ni][nj] = dist[p.first][p.second] + grid[ni][nj];
                    if (grid[ni][nj] == 0) dq.push_front({ni, nj});
                    else dq.push_back({ni, nj});
                }
            }
        }
        
        return false;
    }
};
