class Solution {
public:
    int maxSum(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());

        int res = nums[0];
        if (res <= 0) return res;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) break;
            if (nums[i] == nums[i - 1]) continue;
            res += nums[i];
        }

        return res;
    }
};