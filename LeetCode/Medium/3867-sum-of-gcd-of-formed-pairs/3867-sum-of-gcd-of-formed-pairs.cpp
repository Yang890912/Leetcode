class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n, 0);

        int mx = nums[0];
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            prefixGcd[i] = gcd(nums[i], mx);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long res = 0;
        int l = 0, r = n - 1;
        while (l < r) {
            res += (long long)gcd(prefixGcd[l], prefixGcd[r]);
            l++;
            r--;
        }

        return res;
    }

    int gcd(int a, int b) {
        if (b == 0) return a;
        else return gcd(b, a % b);
    }
};