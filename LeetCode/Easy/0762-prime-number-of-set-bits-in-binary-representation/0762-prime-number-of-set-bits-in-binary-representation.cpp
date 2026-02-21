class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int res = 0;

        for (int i = left; i <= right; i++) {
            if (isPrime(bitCounts(i))) res++;
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

    bool isPrime(int num) {
        if (num == 1) return false;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }
};