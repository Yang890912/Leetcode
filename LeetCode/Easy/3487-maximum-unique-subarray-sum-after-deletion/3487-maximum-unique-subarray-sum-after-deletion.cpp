class Solution {
public:
    int maxSum(vector<int>& nums) {
        int res = INT_MIN;

        int currSum = 0;
        unordered_map<int, int> um;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                currSum = nums[i];
                um[nums[i]] = 1;
            }
            else if (um.count(nums[i]) > 0) continue;
            else {
                if (currSum >= 0 && nums[i] >= 0) currSum += nums[i];
                else if (currSum < 0) {
                    um.clear();
                    currSum = nums[i];
                }
                um[nums[i]] = 1;
            }
            res = max(res, currSum);
        }

        return res;
    }
};