class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int MOD = 1e9 + 7;
        long long prev = 0, base = 0;
        vector<int> prefixSumPowers;
        while (n > 0) {
            if ((n & 1) != 0) {
                prefixSumPowers.push_back(base + prev);
                prev = base + prev;
            }
            n >>= 1;
            base += 1;
        }

        vector<int> res;
        for (const auto& query : queries) {
            if (query[0] == 0) res.push_back(modPow(2, prefixSumPowers[query[1]], MOD));
            else res.push_back(modPow(2, prefixSumPowers[query[1]] - prefixSumPowers[query[0] - 1], MOD));
        }

        return res;
    }

    int modPow(long long base, int exp, int mod) {
        long long result = 1 % mod;
        while (exp > 0) {
            if (exp & 1) result = (result * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }
};