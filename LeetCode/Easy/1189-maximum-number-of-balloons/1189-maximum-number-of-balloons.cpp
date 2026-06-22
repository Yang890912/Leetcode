class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freq(26, 0);
        for (char c : text) {
            freq[c - 'a']++;
        }

        int res = INT_MAX;
        res = min(res, freq['b' - 'a']);
        res = min(res, freq['a' - 'a']);
        res = min(res, freq['l' - 'a'] / 2);
        res = min(res, freq['o' - 'a'] / 2);
        res = min(res, freq['n' - 'a']);

        return res;
    }
};