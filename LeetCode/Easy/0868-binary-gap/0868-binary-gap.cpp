class Solution {
public:
    int binaryGap(int n) {
        int res = 0;
        int l = -1;
        int r = INT_MAX;

        while (n) {
            l++;
            if (n & 1) {
                res = max(res, l - r);
                r = l;
            }
            n >>= 1;
        }

        return res;
    }
};