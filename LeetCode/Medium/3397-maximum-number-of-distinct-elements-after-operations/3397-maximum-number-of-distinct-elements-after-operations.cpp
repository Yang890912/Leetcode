class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int prev = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            int changedNum = max(nums[i] - k, prev + 1);
            if (changedNum <= nums[i] + k) {
                prev = changedNum;
                res++;
            }
        }

        return res;
    }
};