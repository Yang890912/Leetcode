class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);
        vector<int> curr;

        dfs(n, nums, visited, curr);

        return res;
    }

    void dfs(int n, vector<int>& nums, vector<bool>& visited, vector<int>& curr) {
        if (curr.size() == n) {
            res.push_back(curr);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;

            curr.push_back(nums[i]);
            visited[i] = true;
            dfs(n, nums, visited, curr);
            curr.pop_back();
            visited[i] = false;
        }
    }
};