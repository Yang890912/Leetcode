class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            char c1 = tolower(s[i]);
            char c2 = tolower(s[j]);
            if (!('a' <= c1 && c1 <= 'z' || '0' <= c1 && c1 <= '9')) {
                i++;
                continue;
            }
            else if (!('a' <= c2 && c2 <= 'z' || '0' <= c2 && c2 <= '9')) {
                j--;
                continue;
            }
            else if (c1 != c2) return false;

            i++;
            j--;
        }

        return true;
    }
};