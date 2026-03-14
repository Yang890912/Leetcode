class Solution {
public:
    int bitwiseComplement(int n) {
        int tmp = n;
        int max = 0;

        if (n == 0) return 1;
        
        while (tmp) {
            max = 1 + (max << 1);
            tmp >>= 1;
        }

        return max - n;
    }
};