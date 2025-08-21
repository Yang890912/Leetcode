class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        int LCM = lcm(divisor1, divisor2);
        int left = 1, right = INT_MAX;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid - mid / divisor1 >= uniqueCnt1 &&   // A組可以用的數量
                mid - mid / divisor2 >= uniqueCnt2 &&   // B組可以用的數量
                mid - (mid / LCM) >= uniqueCnt1 + uniqueCnt2) // 減掉兩組都不能用的數量 => 至少有一組可以用的數量
                right = mid - 1;
            else
                left = mid + 1;
        }

        return left;
    }

    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    int lcm(long long a, long long b) {
        if (a == 0 || b == 0) return 0;
        long long tmp = a / gcd(a, b) * b;
        return tmp > INT_MAX ? INT_MAX : tmp;
    }
};