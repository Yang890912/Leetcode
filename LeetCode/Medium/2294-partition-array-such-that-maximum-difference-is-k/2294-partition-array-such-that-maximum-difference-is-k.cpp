class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int start = 0;

        while (start < nums.size()) {
            int minNum = nums[start];
            while (start + 1 < nums.size() && nums[start + 1] - minNum <= k) {
                start++;
            }
            res++;
            start++;
        }

        return res;
    }
};