class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        vector<vector<int>> count(2, vector<int>(26, 0));
        for (int i = 0; i < n; i++) {
            count[i % 2][s1[i] - 'a']++;
        }

        for (int i = 0; i < n; i++) {
            count[i % 2][s2[i] - 'a']--;
        }

        for (int c = 0; c < 26; c++) {
            if (count[0][c] || count[1][c])
                return false;
        }

        return true;
    }
};