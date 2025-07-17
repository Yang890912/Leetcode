class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        backtracking(nums, subset, res, 0);
        return res;
    }

    void backtracking(vector<int>& nums, vector<int>& subset, vector<vector<int>>& res, int start) {
        res.push_back(subset);
        for (int i = start; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            backtracking(nums, subset, res, i + 1);
            subset.pop_back();
        }
    }
};