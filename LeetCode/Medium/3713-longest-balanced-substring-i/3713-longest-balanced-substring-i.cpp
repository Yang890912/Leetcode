class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int res = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            int maxFreq = 0;
            int numLetters = 0;
            for (int j = i; j < n; j++) {
                int c = s[j] - 'a';
                freq[c]++;
                if (freq[c] == 1) numLetters++;

                maxFreq = max(maxFreq, freq[c]);
                if (maxFreq * numLetters == j - i + 1) res = max(res, j - i + 1);
            }
        }

        return res;
    }
};