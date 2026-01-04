class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int res = 0;
        for (int i = 0; i < m - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                
                unordered_set<int> st;
                for (int ii = 0; ii < 3; ii++) {
                    for (int jj = 0; jj < 3; jj++) {
                        if (grid[i + ii][j + jj] > 9 || grid[i + ii][j + jj] < 1) break;
                        st.insert(grid[i + ii][j + jj]);
                    }
                }

                if (st.size() < 9) continue;

                if (grid[i][j] + grid[i + 1][j] + grid[i + 2][j] != 15) continue;
                if (grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1] != 15) continue;
                if (grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2] != 15) continue;

                if (grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] != 15) continue;
                if (grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j] != 15) continue;

                if (grid[i][j] + grid[i][j + 1] + grid[i][j + 2] != 15) continue;
                if (grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2] != 15) continue;
                if (grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2] != 15) continue;

                res++;
            }
        }

        return res;
    }
};