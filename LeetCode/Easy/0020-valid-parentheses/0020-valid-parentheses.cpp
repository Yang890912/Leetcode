class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> tb;

        tb[')'] = '(';
        tb['}'] = '{';
        tb[']'] = '[';
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') st.push(c);
            else if (st.empty() || tb[c] != st.top()) return false;
            else st.pop();
        }

        return st.empty();
    }
};