class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> isPalindrome(s.size(), vector<bool>(s.size(), false));
        int start = 0, end = 0;

        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < s.size(); j++) {
                if (j + i >= s.size()) continue;

                if (s[j] == s[j + i]) {
                    if (i >= 2) isPalindrome[j][j + i] = isPalindrome[j + 1][j + i - 1];
                    else isPalindrome[j][j + i] = true;   

                    if (isPalindrome[j][j + i] && end - start < i) {
                        start = j;
                        end = j + i;
                    }   
                }
            }
        }

        return s.substr(start, end - start + 1);
    }
};