class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for (int num : nums) {
            maxOr |= num;
        }

        return backtrack(nums, 0, maxOr, 0);
    }

    int backtrack(vector<int>& nums, int idx, int maxOr, int currOr) {
        if (idx == nums.size()) {
            if (currOr == maxOr) return 1;
            else return 0;
        }

        if (currOr == maxOr) return 1 << (nums.size() - idx);

        return backtrack(nums, idx + 1, maxOr, currOr | nums[idx]) + backtrack(nums, idx + 1, maxOr, currOr);
    }
};