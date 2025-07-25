class Solution {
public:
    int remove(string& s, string pattern, int score) {
        int gain = 0;
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (st.empty()) st.push(s[i]);
            else if (st.top() != pattern[0] || s[i] != pattern[1]) st.push(s[i]);
            else {
                gain += score;
                st.pop();
            }
        }

        s.clear();
        while (!st.empty()) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());

        return gain;
    }

    int maximumGain(string s, int x, int y) {
        int maxGain = 0;
        if (x > y) {
            maxGain += remove(s, "ab", x);
            maxGain += remove(s, "ba", y);
        }
        else {
            maxGain += remove(s, "ba", y);
            maxGain += remove(s, "ab", x);
        }

        return maxGain;
    }
};