class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.size() > 2) {
            string _s;
            for (int i = 0; i < s.size() - 1; i++) {
                _s += ((s[i] - '0') + (s[i + 1] - '0')) % 10 + '0';
            }
            s = _s;
        }

        return s[0] == s[1] ? true : false;
    }
};