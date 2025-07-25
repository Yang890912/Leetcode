class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> elements;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                elements.push_back(grid[i][j]);
            }
        }

        sort(elements.begin(), elements.end());
        int target = elements[elements.size() / 2];
        int res = 0;
        for (int i = 0; i < elements.size(); i++) {
            int k = abs(target - elements[i]);
            if (k % x != 0) return -1;
            res += k / x;
        }

        return res;

    }
};