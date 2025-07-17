class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<long long> Lmax(n, 0);
        vector<long long> Rmax(n, 0);

        Lmax[0] = max(nums[0], (int)Lmax[0]);
        Rmax[n - 1] = max(nums[n - 1], (int)Rmax[n - 1]);

        for (int i = 1; i < n; i++) {
           Lmax[i] = max((int)Lmax[i - 1], nums[i]);
           Rmax[n - 1 - i] = max((int)Rmax[n - i], nums[n - 1 - i]);
        }

        long long res = 0;
        for (int i = 1; i < n - 1; i++) {
           res = max(res, (Lmax[i - 1] - nums[i]) * Rmax[i + 1]);
        }

        return res;
    }
};