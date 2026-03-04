class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int res = 0;
        vector<int> countRow(m, 0), countCol(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    countRow[i]++;
                    countCol[j]++;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            if (countRow[i] != 1) continue;
            for (int j = 0; j < n; j++) {
                if (countCol[j] != 1) continue;
                if (countCol[j] == 1 && mat[i][j] == 1) {
                    res++;
                    break;
                }
            }
        }

        return res;
    }
};