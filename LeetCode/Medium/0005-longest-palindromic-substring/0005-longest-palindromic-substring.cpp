class Solution {
public:
    string longestPalindrome(string s) {
        string res;

        for (int i = 0; i < s.size(); i++) {
            int len = 1;
            len = max(len, palindrome(s, i, i));
            if (i + 1 < s.size() && s[i] == s[i + 1]) 
                len = max(len, palindrome(s, i, i + 1));

            if (len > res.size()) 
                res = s.substr(i - (len - 1) / 2, len);
        }

        return res;
    }

    int palindrome(string s, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        return r - l - 1;
    }
};