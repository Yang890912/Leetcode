class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> st(26, 0);
        vector<int> tt(26, 0);

        for (int i = 0; i < s.size(); i++) {
            st[s[i] - 'a']++;
            tt[t[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (st[i] != tt[i]) return false;
        }
        
        return true;
    }
};