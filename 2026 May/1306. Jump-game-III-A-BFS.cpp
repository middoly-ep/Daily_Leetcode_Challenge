#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(int x, int n, vector<bool> &visited){
        return x >= 0 && x < n && !visited[x];
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        if (!isValid(start, n, visited)) return false;
        visited[start] = true;
        queue<int> q;
        q.push(start);
        
        while (!q.empty()){
            int idx = q.front();
            int val = arr[idx];
            if (val == 0) return true;
            q.pop();
            if (isValid(idx + val, n, visited)){
                q.push(idx + val);
                visited[idx + val] = true;
            }
            if (isValid(idx - val, n, visited)){
                q.push(idx - val);
                visited[idx - val] = true;
            }
        }
        return false;
    }
};
