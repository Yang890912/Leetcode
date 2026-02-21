class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};
        int res = 0;

        for (int i = left; i <= right; i++) {
            if (primes.count(bitCounts(i))) res++;
        }

        return res;
    }

    int bitCounts(int num) {
        int count = 0;
        while (num) {
            if (num & 1) count++;
            num >>= 1;
        }
        return count;
    }
};