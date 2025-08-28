class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            vector<int> bottomLeft;
            int x = i;
            int y = 0;
            while (x < m && y < n) {
                bottomLeft.push_back(grid[x++][y++]);
            }
            sort(bottomLeft.rbegin(), bottomLeft.rend());

            int j = 0;
            x = i;
            y = 0;
            while (x < m && y < n) {
                res[x++][y++] = bottomLeft[j++];
            }
        }

        for (int i = 1; i < n; i++) {
            vector<int> topRight;
            int x = 0;
            int y = i;
            while (x < m && y < n) {
                topRight.push_back(grid[x++][y++]);
            }
            sort(topRight.begin(), topRight.end());

            int j = 0;
            x = 0;
            y = i;
            while (x < m && y < n) {
                res[x++][y++] = topRight[j++];
            }
        }

        return res;
    }
};