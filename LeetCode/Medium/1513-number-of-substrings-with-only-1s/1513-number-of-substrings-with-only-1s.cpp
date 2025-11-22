class Solution {
public:
    int numSub(string s) {
        vector<long long> numOfSubstring(1e5 + 1, 0);
        const long long MOD = 1e9 + 7;
        long long res = 0;

        for (long long i = 1; i <= 1e5; i++) {
            numOfSubstring[i] = (i + 1) * i / 2 % MOD;
        }

        int i = 0;
        while (i < s.size()) {
            if (s[i] == '0') {
                i++;
                continue;
            }
            
            int len = 0;
            while (i < s.size() && s[i] == '1') {
                len++;
                i++;
            }

            res += numOfSubstring[len];
            res %= MOD;
        }

        return res;
    }
};