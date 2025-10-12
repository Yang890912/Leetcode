class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, long long> spellPower;
        vector<int> keys;
        for (int p : power) spellPower[p] += p;
        for (auto& [key, val] : spellPower) keys.push_back(key);

        sort(keys.begin(), keys.end());

        vector<long long> dp(keys.size(), 0);
        dp[0] = spellPower[keys[0]];
        for (int i = 1; i < keys.size(); i++) {
            for (int j = i - 1; j >= max(0, i - 3); j--) {
                if (keys[i] - keys[j] > 2) dp[i] = max(dp[i], spellPower[keys[i]] + dp[j]);
                else dp[i] = max(dp[i], max(spellPower[keys[i]], dp[j]));
            }
        }

        return dp[keys.size() - 1];
    }
};