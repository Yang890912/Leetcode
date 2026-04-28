class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        int remain = grid[0][0] % x;
        vector<int> nums;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] % x != remain) return -1;
                nums.push_back(grid[i][j]);
            }
        }

        sort(nums.begin(), nums.end());
        int mid = nums[nums.size() / 2];
        int res = 0;
        for (int num : nums) {
            res += abs(num - mid) / x;
        }

        return res;
    }
};