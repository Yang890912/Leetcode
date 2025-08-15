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
        string news = "";
        for (int i = 0; i < s.size(); i++) {
            if (news == "") news += s[i];
            else if (s[i] == pattern[1] && news.back() == pattern[0]) {
                gain += canGain;
                news.pop_back();
            }
            else news += s[i];
        }

        return news;
    }
};