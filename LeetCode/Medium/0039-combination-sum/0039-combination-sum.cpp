class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        backtrack(candidates, target, curr, 0);
        return res;
    }

    void backtrack(vector<int>& candidates, int target, vector<int>& curr, int i) {
        if (i >= candidates.size() || target < 0) return;

        if (target == 0) {
            res.push_back(curr);
            return;
        }

        curr.push_back(candidates[i]);
        backtrack(candidates, target - candidates[i], curr, i);
        curr.pop_back();
        backtrack(candidates, target, curr, i + 1);

        return;
    }
};