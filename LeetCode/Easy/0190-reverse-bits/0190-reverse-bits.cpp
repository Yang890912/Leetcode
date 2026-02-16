class Solution {
public:
    int reverseBits(int n) {
        int numBits = 31;
        int res = 0;
        while (numBits--) {
            res |= (n & 1);
            n >>= 1;
            res <<= 1;
        }

        return res;
    }
};