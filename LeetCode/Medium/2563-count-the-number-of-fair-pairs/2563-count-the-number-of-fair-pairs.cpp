class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        long long res = 0;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            int lowerBound = lower - nums[i];
            int upperBound = upper - nums[i];
            auto right = upper_bound(nums.begin() + i + 1, nums.end(), upperBound);
            auto left = lower_bound(nums.begin() + i + 1, nums.end(), lowerBound);
            res += (right - left);
        }

        return res;
    }
};