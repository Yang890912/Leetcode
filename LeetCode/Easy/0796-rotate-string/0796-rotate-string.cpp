class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();

        if (goal.size() != n) return false;

        for (int i = 0; i < n; i++) {
            s = s[n - 1] + s.substr(0, n - 1);
            if (s == goal) return true;
        }

        return false;
    }
};