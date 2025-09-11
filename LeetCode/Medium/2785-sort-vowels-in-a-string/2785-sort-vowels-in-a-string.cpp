class Solution {
public:
    string sortVowels(string s) {
        string res = s;
        vector<char> vowels;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
                s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                vowels.push_back(s[i]);
                res[i] = ' ';
            }
            else {
                res[i] = s[i];
            }
        }
        sort(vowels.begin(), vowels.end());

        int j = 0;
        for (int i = 0; i < res.size(); i++) {
            if (res[i] == ' ') res[i] = vowels[j++];
        }

        return res;
    }
};