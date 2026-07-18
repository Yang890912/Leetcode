class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn = INT_MAX;
        int mx = INT_MIN;

        for (int num : nums) {
            if (num > mx) mx = num;
            if (num < mn) mn = num;
        }

        return gcd(mx, mn);
    }

    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }
};