class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int ai = a.size() - 1;
        int bi = b.size() - 1;
        int carry = 0;
        while (ai >= 0 || bi >= 0) {
            int sum = carry;
            sum += (ai >= 0) ? a[ai--] - '0' : 0;
            sum += (bi >= 0) ? b[bi--] - '0' : 0;

            carry = sum / 2;
            sum %= 2;
            res.push_back('0' + sum);
        }

        if (carry >= 1) res.push_back('1');

        reverse(res.begin(), res.end());

        return res;
    }
};