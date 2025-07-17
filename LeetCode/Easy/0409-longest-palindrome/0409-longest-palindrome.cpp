class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> lowNum(26, 0);
        vector<int> upNum(26, 0);
        int res = 0;
        int bonus = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') lowNum[s[i] - 'a']++;
            else if (s[i] >= 'A' && s[i] <= 'Z') upNum[s[i] - 'A']++;
        }

        for (int i = 0; i < 26; i++) {
            res += lowNum[i] / 2 + upNum[i] / 2;
            if (bonus == 0) {
                bonus = max(bonus, lowNum[i] % 2);
                bonus = max(bonus, upNum[i] % 2);
            }
        }
        
        return 2 * res + bonus;
    }
};