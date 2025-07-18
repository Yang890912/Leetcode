class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        return transStr(countAndSay(n - 1));
    }

    string transStr(string s) {
        string output = "";
        int freq = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i == 0 || s[i - 1] == s[i]) freq++;
            else {
                output += to_string(freq);
                output += to_string(s[i - 1] - '0');
                freq = 1;
            }
        }
        output += to_string(freq);
        output += to_string(s[s.size() - 1] - '0');
        return output;
    }   
};