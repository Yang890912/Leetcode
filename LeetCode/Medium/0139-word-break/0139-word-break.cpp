class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int m = s.size();
        int n = wordDict.size();
        vector<bool> dp(m + 1, false);
        dp[0] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int start = i + 1 - wordDict[j].size();
                if (start >= 0 && dp[start] && s.substr(start, wordDict[j].size()) == wordDict[j])
                    dp[i + 1] = true; 
            }
        }

        return dp[m];
    }
};