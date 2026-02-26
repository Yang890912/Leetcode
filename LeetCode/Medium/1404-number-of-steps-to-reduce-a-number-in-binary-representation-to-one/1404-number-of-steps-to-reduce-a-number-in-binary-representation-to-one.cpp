class Solution {
public:
    int numSteps(string s) {
        int n = s.size();
        int res = 0;
        int carry = 0;
        for (int i = n - 1; i > 0; i--) {
            int bit = s[i] - '0';
            res += 1 + (carry ^ bit);
            carry |= bit;
        }

        return res + carry;
    }
};