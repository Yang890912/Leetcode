class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = INT_MAX;

        for (int i = 0; i < n - k + 1; i++) {
            res = min(res, abs(nums[i] - nums[i + k - 1]));
        }

        return res;
    }
};