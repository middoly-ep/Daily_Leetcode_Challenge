#include <map>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool isValid(int x, int n, const vector<bool> &visited){
        return x >= 0 && x < n && !visited[x];
    }

    int minJumps(vector<int>& arr) {
        int n = arr.size();
        vector<bool> visited(n, false);
        unordered_map<int, vector<int>> equals;
        for (int i = 0; i < n; i++){
            equals[arr[i]].push_back(i);
        }

        queue<int> q;
        q.push(0);
        int jumps = 0;
        visited[0] = true;
        while (!q.empty()){
            int tmp = q.size();
            while (tmp--){
                int idx = q.front();
                if (idx == n - 1) return jumps;
                q.pop();
                if (isValid(idx + 1, n, visited)) q.push(idx + 1);
                if (isValid(idx - 1, n, visited)) q.push(idx - 1); 
                
                if (equals.count(arr[idx]) != 0){
                    for (int x : equals[arr[idx]]){
                        if (!visited[x]) {q.push(x); visited[x] = true;}
                    }
                    equals.erase(arr[idx]);
                }
            }
            jumps++;
        }
        return jumps;
    }
};
