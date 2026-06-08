class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> res(n, 0);
        int l = 0;
        int r = n - 1;
        for (int i = 0, j = n - 1; i < n; i++, j--){
            if (nums[i] < pivot){
                res[l++] = nums[i];
            }
            if (nums[j] > pivot){
                res[r--] = nums[j];
            }
        }
        while (l <= r){
            res[l] = pivot;
            l++;
        }
        return res;
    }
};
