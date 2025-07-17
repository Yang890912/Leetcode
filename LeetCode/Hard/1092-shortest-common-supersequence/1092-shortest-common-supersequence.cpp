class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int s1 = str1.size();
        int s2 = str2.size();
        vector<vector<int>> dp(s1 + 1, vector<int>(s2 + 1, 0));

        for (int i = 1; i <= s1; i++) {
            for (int j = 1; j <= s2; j++) {
                if (str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        int row = s1;
        int column = s2;
        string scs;

        while (row > 0 && column > 0) {
            if (str1[row - 1] == str2[column - 1]) {
                scs.push_back(str1[row - 1]);
                row--;
                column--;
            }
            else if (dp[row - 1][column] < dp[row][column - 1]) {
                scs.push_back(str2[column - 1]);
                column--;
            }
            else {
                scs.push_back(str1[row - 1]);
                row--;
            }
        }

        while (row > 0) {
            scs.push_back(str1[row - 1]);
            row--;
        }

        while (column > 0) {
            scs.push_back(str2[column - 1]);
            column--;
        }

        reverse(scs.begin(), scs.end());

        return scs;
    }
};