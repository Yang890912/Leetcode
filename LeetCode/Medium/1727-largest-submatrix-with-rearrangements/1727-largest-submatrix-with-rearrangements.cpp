class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;

        for (int j = 0; j < n; j++) {
            for (int i = 1; i < m; i++) {
                if (matrix[i][j] == 1) matrix[i][j] = matrix[i - 1][j] + 1;
            }
        }

        for (int i = 0; i < m; i++) {
            sort(matrix[i].rbegin(), matrix[i].rend());
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) break;
                res = max(res, matrix[i][j] * (j + 1));
            }
        }

        return res;
    }
};