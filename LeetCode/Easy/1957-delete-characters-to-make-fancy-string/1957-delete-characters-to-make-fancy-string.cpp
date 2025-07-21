class Solution {
public:
    string makeFancyString(string s) {
        string res = ""; 

        int accum = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i == 0 || s[i] != s[i - 1]) accum = 0;
            else if (s[i] == s[i - 1]) accum += 1;
            
            if (accum < 2) res += s[i];
        }

        return res;
    }
};