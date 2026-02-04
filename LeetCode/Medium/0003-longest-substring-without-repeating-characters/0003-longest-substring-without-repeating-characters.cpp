class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, r = 0;
        int res = 0;
        unordered_set<char> used;

        while (r < n && l < n) {
            if (!used.count(s[r])) {
                used.insert(s[r]);
                res = max(r - l + 1, res);
                r++;
            }
            else {
                while (used.count(s[r])) {
                    used.erase(s[l]);
                    l++;
                }
            }
        }

        return res;
    }
};