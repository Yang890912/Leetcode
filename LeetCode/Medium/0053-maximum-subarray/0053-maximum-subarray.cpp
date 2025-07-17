class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currMax = -1000001;
        int res = -1000001;
        for (int i = 0; i < nums.size(); i++) {
            currMax = max(nums[i], currMax + nums[i]);
            res = max(res, currMax);
        }
        return res;
    }
};