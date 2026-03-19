class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        vector<vector<int>> numX(m, vector<int>(n, 0));
        vector<vector<int>> numY(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0);
                else if (i == 0) {
                    numX[i][j] = numX[i][j - 1];
                    numY[i][j] = numY[i][j - 1];
                }
                else if (j == 0) {
                    numX[i][j] = numX[i - 1][j];
                    numY[i][j] = numY[i - 1][j];
                }
                else {
                    numX[i][j] = numX[i][j - 1] + numX[i - 1][j] - numX[i - 1][j - 1];
                    numY[i][j] = numY[i][j - 1] + numY[i - 1][j] - numY[i - 1][j - 1];
                }

                if (grid[i][j] == 'X') numX[i][j]++;
                else if (grid[i][j] == 'Y') numY[i][j]++;

                if (numX[i][j] > 0 && numX[i][j] == numY[i][j]) res++;
            }
        }

        return res;
    }
};