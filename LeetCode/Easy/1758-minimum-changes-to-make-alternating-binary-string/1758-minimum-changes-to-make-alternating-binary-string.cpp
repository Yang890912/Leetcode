class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int even = 0, odd = 0;
        int res = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') continue;

            if (i % 2) odd++;
            else even++;
        }

        res = min(res, odd + (n + 1) / 2 - even);
        res = min(res, even + n / 2 - odd);

        return res;
    }
};