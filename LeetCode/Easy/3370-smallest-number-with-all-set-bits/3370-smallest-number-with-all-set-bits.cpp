class Solution {
public:
    int smallestNumber(int n) {
        int res = 0;
        int added = 1;
            
        while (true) {
            res += added;
            if (res >= n) break;
            added *= 2;
        }

        return res;
    }
};