class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> um;
        const long long MOD = 1e9 + 7;

        for (int i = 0; i < points.size(); i++) {
            um[points[i][1]]++;
        }

        long long res = 0;
        long long prefixSum = 0;
        for (auto& p : um) {
            long long numPoints = p.second;
            
            if (numPoints < 2) continue;

            long long comb = (numPoints * (numPoints - 1)) / 2 % MOD;

            if (prefixSum == 0) {
                prefixSum += comb % MOD;
                continue;
            }

            res += comb * prefixSum;
            prefixSum += comb;

            res %= MOD;
            prefixSum %= MOD;
        }

        return res;
    }
};