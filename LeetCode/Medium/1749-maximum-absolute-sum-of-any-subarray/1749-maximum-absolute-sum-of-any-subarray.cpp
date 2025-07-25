class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int res = abs(nums[0]);
        int currMax = 0;
        int currMin = 0;
        vector<int> prefixSum;

        if (nums[0] >= 0) currMax = nums[0];
        else currMin = nums[0];

        prefixSum.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            prefixSum.push_back(prefixSum[i - 1] + nums[i]);

            if (prefixSum[i] >= 0) {
                res = max(res, prefixSum[i] - currMin);
                currMax = max(currMax, prefixSum[i]);
            }
            else {
                res = max(res, abs(prefixSum[i] - currMax));
                currMin = min(currMin, prefixSum[i]);
            }
        }

        return res;
    }
};