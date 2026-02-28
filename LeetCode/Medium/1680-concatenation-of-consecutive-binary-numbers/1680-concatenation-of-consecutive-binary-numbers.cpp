class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        long long res = 0;
        for (int i = 1; i <= n; i++) {
            int num = i;
            while (num) {
                num >>= 1;
                res = (res << 1) % MOD;
            }
            // res = (res + i) % MOD;
        }

        return res;
    }
};