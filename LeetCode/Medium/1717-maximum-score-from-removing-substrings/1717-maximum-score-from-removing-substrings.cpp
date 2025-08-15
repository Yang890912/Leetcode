class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int gain = 0;

        if (x >= y) {
            s = calGain(s, gain, x, "ab");
            calGain(s, gain, y, "ba");
        } 
        else {
            s = calGain(s, gain, y, "ba");
            calGain(s, gain, x, "ab");
        }

        return gain;
    }

    string calGain(string s, int& gain, int canGain, string pattern) {
        string newS = "";

        for (int i = 0; i < s.size(); i++) {
            if (newS == "") newS += s[i];
            else if (s[i] == pattern[1] && newS.back() == pattern[0]) {
                gain += canGain;
                newS.pop_back();
            }
            else newS += s[i];
        }

        return newS;
    }
};