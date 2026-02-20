class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        res.push_back({});
        
        backtrack(nums, res, n, 0);

        return res;
    }

    void backtrack(vector<int>& nums, vector<vector<int>>& res, int n, int idx) {
        if (idx >= n) return;

        int size = res.size();
        for (int i = 0; i < size; i++) {
            vector<int> tmp = res[i];
            tmp.push_back(nums[idx]);
            res.push_back(tmp);
        }

        backtrack(nums, res, n, idx + 1);
    }
};