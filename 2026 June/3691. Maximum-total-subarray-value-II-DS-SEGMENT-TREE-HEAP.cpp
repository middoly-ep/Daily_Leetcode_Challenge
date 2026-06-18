#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    struct node{
        int l, r, diff;

        bool operator < (const node& other) const {
            return diff < other.diff;
        }
    };
    vector<int> max_segment_tree;
    vector<int> min_segment_tree;
    vector<int> arr;

    void build(int id, int l, int r){
        if (l == r){
            max_segment_tree[id] = arr[l];
            min_segment_tree[id] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * id, l, mid);
        build(2 * id + 1, mid + 1, r);

        max_segment_tree[id] = max(max_segment_tree[2 * id], max_segment_tree[2 * id + 1]);
        min_segment_tree[id] = min(min_segment_tree[2 * id], min_segment_tree[2 * id + 1]);
    }
    int query_max(int id, int l, int r, int u, int v){
        if (r < u || l > v) return INT_MIN;
        if (l >= u && r <= v) return max_segment_tree[id];
        int mid = (l + r) / 2;
        int left_max = query_max(2 * id, l, mid, u, v);
        int right_max = query_max(2 * id + 1, mid + 1, r, u, v);
        return max(left_max, right_max);
    }
    int query_min(int id, int l, int r, int u, int v){
        if (r < u || l > v) return INT_MAX;
        if (l >= u && r <= v) return min_segment_tree[id];
        int mid = (l + r)/2;
        int left_min = query_min(2 * id, l, mid, u, v);
        int right_min = query_min(2 * id + 1, mid + 1, r, u, v);
        return min(left_min, right_min);
    }
    int query(int u, int v, int n){
        return query_max(1, 0, n - 1, u, v) - query_min(1, 0, n - 1, u, v);
    }

    long long maxTotalValue(vector<int>& nums, int k) {
        arr = nums;
        int n = nums.size();
        max_segment_tree.resize(4 * n);
        min_segment_tree.resize(4 * n);
        build(1, 0, n - 1);

        set<pair<int, int>> visited;
        priority_queue<node> max_heap;
        max_heap.push({0, n - 1, query(0, n - 1, n)});
        visited.insert({0, n - 1});
        long long res = 0;
        while (k-- && !max_heap.empty()){
            node tmp = max_heap.top();
            max_heap.pop();
            if (visited.count({tmp.l + 1, tmp.r}) == 0 && tmp.l + 1 <= tmp.r){
                visited.insert({tmp.l + 1, tmp.r});
                max_heap.push({tmp.l + 1, tmp.r, query(tmp.l + 1, tmp.r, n)});
            }
            if (visited.count({tmp.l, tmp.r - 1}) == 0 && tmp.l <= tmp.r - 1){
                visited.insert({tmp.l, tmp.r - 1});
                max_heap.push({tmp.l, tmp.r - 1, query(tmp.l, tmp.r - 1, n)});
            }
            res += tmp.diff;
        }
        return res;
    }
};
