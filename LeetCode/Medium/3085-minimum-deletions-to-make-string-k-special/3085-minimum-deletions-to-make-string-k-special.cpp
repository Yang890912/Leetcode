class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        int res = 1000001;

        for (int i = 0; i < word.size(); i++) {
            freq[word[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) continue;

            int del = 0;
            for (int j = 0; j < 26; j++) {
                if (i == j) continue;
                else if (freq[j] < freq[i]) del += freq[j];
                else del += max(0, freq[j] - freq[i] - k);
            }
            res = min(res,  del);
        }

        return res;
    }
};