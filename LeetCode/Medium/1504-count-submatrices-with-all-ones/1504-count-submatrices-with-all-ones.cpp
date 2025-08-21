class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int res = 0;
        vector<int> dp(mat[0].size());
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 0) dp[j] = 0;
                else dp[j] += 1;
            }

            for (int j = 0; j < mat[0].size(); j++) {
                int mint = dp[j];
                for (int k = j; k >= 0 && mint > 0; k--) {
                    mint = min(mint , dp[k]);
                    res += mint;
                }
            }
        }

        return res;
    }
};