class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        const int sLen = s.size();
        const int pLen = p.size();
        vector<int> res;
        vector<int> freq(26, 0);

        for (char c : p) freq[c - 'a']++; 

        int l = 0, r = 0;
        while (l < sLen) {
            while (r < sLen && freq[s[r] - 'a']) {
                freq[s[r] - 'a']--;
                r++;
            }

            if (r - l == pLen) res.push_back(l);

            freq[s[l] - 'a']++;
            l++;
        }

        return res;
    }
};