class Solution {
public:
    string processStr(string s) {
        string res;
        
        for (char c : s) {
            if (c <= 'z' && c >= 'a') res += c;
            else if (c == '*' && res.size() > 0) res.pop_back();
            else if (c == '#') res += res;
            else if (c == '%') reverse(res.begin(), res.end());
        }

        return res;
    }
};