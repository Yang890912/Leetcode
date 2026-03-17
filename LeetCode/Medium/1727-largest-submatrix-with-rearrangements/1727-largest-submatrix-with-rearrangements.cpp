class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;
        vector<vector<int>> cum(m, vector<int>(n, 0));

        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int i = 0; i < m; i++) {
                if (matrix[i][j] == 0) sum = 0;
                else sum++;
                cum[i][j] = sum;
            }
        }

        for (int i = 0; i < m; i++) {
            sort(cum[i].rbegin(), cum[i].rend());
            for (int j = 0; j < n; j++) {
                if (cum[i][j] == 0) break;
                res = max(res, cum[i][j] * (j + 1));
            }
        }

        return res;
    }
};