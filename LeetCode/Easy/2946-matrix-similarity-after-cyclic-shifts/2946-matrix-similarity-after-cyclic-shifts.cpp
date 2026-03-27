class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> shifted(m, vector<int>(n, 0));

        k %= n;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i % 2 == 0) {
                    shifted[i][j] = mat[i][(j + k) % n];
                }
                else {
                    shifted[i][j] = mat[i][(j - k + n) % n];
                }
            }
        }

        return shifted == mat;

    }
};