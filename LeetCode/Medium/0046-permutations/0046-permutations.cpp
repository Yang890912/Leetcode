class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        vector<int> permutation;
        vector<bool> visited(nums.size(), false);

        dfs(nums, 0, visited, permutation, permutations);

        return permutations;
    }

    void dfs(vector<int>& nums, int level, vector<bool>& visited, vector<int>& permutation, vector<vector<int>>& permutations) {        
        if (level >= nums.size()) {
            permutations.push_back(permutation);
            return;
        }
 
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) continue;
            else {
                visited[i] = true;
                permutation.push_back(nums[i]);

                dfs(nums, level + 1, visited, permutation, permutations);

                permutation.pop_back();
                visited[i] = false;
            }
        }
    }
};