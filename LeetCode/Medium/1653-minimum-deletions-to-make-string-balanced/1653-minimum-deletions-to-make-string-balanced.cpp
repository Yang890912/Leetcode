class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int res = n;
        vector<int> prefixBCounts(n, 0);
        vector<int> suffixACounts(n, 0);

        for (int i = 1; i < n; i++) {
            prefixBCounts[i] = prefixBCounts[i - 1] + (s[i - 1] == 'b');
        }
        for (int i = n - 2; i >= 0; i--) {
            suffixACounts[i] = suffixACounts[i + 1] + (s[i + 1] == 'a');
        }

        for (int i = 0; i < n; i++) {
            res = min(res, prefixBCounts[i] + suffixACounts[i]);
        }

        return res;
    }
};