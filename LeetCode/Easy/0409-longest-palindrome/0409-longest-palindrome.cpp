class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> freq('z' + 1, 0);
        int res = 0;

        for (char c : s) {
            freq[c]++;
            if (freq[c] == 2) {
                res += 2;
                freq[c] = 0;
            }
        }

        for (char c : s) {
            if (freq[c] == 1) {
                res++;
                break;
            }
        }

        return res;
    }
};