class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int m = nums.size();
        vector<int> left(m, 0);
        vector<int> right(m, 0);

        left[0] = 1;
        for (int i = 1; i < m; i++) {
            if (nums[i] > nums[i - 1]) left[i] = left[i - 1] + 1;
            else left[i] = 1;
        }

        right[m - 1] = 1;
        for (int i = m - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) right[i] = right[i + 1] + 1;
            else right[i] = 1;
        }

        int res = 0;
        for (int i = 0; i < m - 1; i++) {
            res = max(res, min(left[i], right[i + 1]));
        }

        return res;
    }
};