class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int res = 0;

        int i = 0;
        int preLen = 0;
        while (i < n) {
            int len = 1;
            while (i + 1 < n && s[i] == s[i + 1]) {
                len++;
                i++;
            }

            res += min(preLen, len);
            preLen = len;
            i++;
        }

        return res;
    }
};