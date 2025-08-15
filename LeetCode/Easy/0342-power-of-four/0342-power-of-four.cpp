class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;

        bitset<31> x(n);
        if (x.count() != 1) return 0;
        for (int i = 1; i < 31; i += 2) {
            if (x[i] == 1) return false;
        }
        
        return true;
    }
};