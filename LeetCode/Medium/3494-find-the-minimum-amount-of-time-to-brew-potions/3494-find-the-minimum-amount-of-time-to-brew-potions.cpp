class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();

        vector<long long> done(n, 0);
        for (int j = 0; j < m; j++) {
            long long curr = done[0];
            for (int i = 0; i < n; i++) {
                done[i] = max(done[i], curr) + 1LL * skill[i] * mana[j];
                curr = done[i];
            }

            for (int i = n - 2; i >= 0; i--) {
                done[i] = done[i + 1] - 1LL * skill[i + 1] * mana[j];
            }
        }

        return done[n - 1];
    }
};