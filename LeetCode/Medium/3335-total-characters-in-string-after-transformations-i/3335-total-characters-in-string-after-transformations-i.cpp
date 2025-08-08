class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<long long> freq(26, 0);
        int mod = 1e9 + 7;
        for (char c : s) {
            freq[c - 'a']++;
        }

        while (t--) {
            vector<long long> newFreq(26, 0);
            for (int i = 1; i < 26; i++) {
                newFreq[i] = freq[i - 1] % mod;
            }
            newFreq[0] += freq[25]; 
            newFreq[1] += freq[25];
            freq = newFreq;
        }

        long long res = 0;
        for (int i = 0; i < 26; i++) {
            res += freq[i];
        }

        return res % mod;
    }
};