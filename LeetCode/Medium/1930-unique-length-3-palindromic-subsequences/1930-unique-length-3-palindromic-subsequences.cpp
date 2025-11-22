class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int res = 0;
        set<char> marked;
        
        for (int i = 0; i < s.size(); i++) {
            if (marked.count(s[i]) != 0) continue;
            marked.insert(s[i]);

            for (int j = s.size() - 1; j > i; j--) {
                if (s[i] == s[j]) {
                    set<char> mid;
                    for (int k = i + 1; k < j; k++) mid.insert(s[k]);
                    res += mid.size();
                    break;
                }
            }
        }

        return res;
    }
};