class Solution {
public:
    string addBinary(string a, string b) {
        int aLast = a.size() - 1;
        int bLast = b.size() - 1;
        int carryBit = 0;
        string res = "";
        
        while (aLast >= 0 || bLast >= 0 || carryBit != 0) {
            int sum = carryBit;
            if (aLast >= 0) sum += a[aLast--] - '0';
            if (bLast >= 0) sum += b[bLast--] - '0';

            res = to_string(sum % 2) + res;
            carryBit = sum / 2;
        }
        return res;
    }
};