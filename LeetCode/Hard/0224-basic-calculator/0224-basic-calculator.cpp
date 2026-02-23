class Solution {
public:
    int calculate(string s) {
        int res = 0;

        stack<int> st;
        long long num = 0;
        int sign = 1;
        for (char& c : s) {
            if ('0' <= c && c <= '9') {
                num = num * 10 + (c - '0');
            }
            else if (c == '-' || c == '+') {
                res += sign * num;
                num = 0;
                sign = (c == '+') ? 1 : -1; 
            }
            else if (c == '(') {
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            }
            else if (c == ')') {
                res += sign * num;
                res *= st.top(); st.pop();
                res += st.top(); st.pop();
                num = 0;
            }
        }
        res += sign * num;

        return res;
    }
};