class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if (digits.back() != 9) {
            digits[n - 1] += 1;
            return digits;
        }

        vector<int> res;
        int carry = 0;
        if (digits[n - 1] == 9) {
            res.push_back(0);
            carry = 1;
        }
        else {
            res.push_back(digits[n - 1] + 1);
        }

        for (int i = n - 2; i >= 0; i--) {
            if (digits[i] + carry >= 10) { 
                res.insert(res.begin(), 0);
                carry = 1;
            }
            else {
                res.insert(res.begin(), digits[i] + carry);
                carry = 0;
            }
        }

        if (carry == 1) res.insert(res.begin(), 1);

        return res;
    }
};