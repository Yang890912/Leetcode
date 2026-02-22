class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        string res = "";
        unordered_map<char, int> charCount;
        for (char& c : t) charCount[c]++;

        int remain = charCount.size();
        int l = 0;
        int r = 0;
        while (l < s.size() && r < s.size()) {
            if (charCount.count(s[r]) == 0) {
                r++;
                continue;
            }
            charCount[s[r]]--;
            if (charCount[s[r]] == 0) remain--;

            while (remain == 0) {        
                if (charCount.count(s[l]) == 0) {
                    l++;
                    continue;
                }
                charCount[s[l]]++;
                if (charCount[s[l]] >= 1) {
                    if (res.size() == 0 || r - l + 1 < res.size()) res = s.substr(l, r - l + 1);
                    remain++;
                }
                l++;
            }
            r++;
        }

        return res;
    }
};