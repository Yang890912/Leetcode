class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size() - 1;
        bool dup = false;

        for (int num : nums) {
            int val = abs(num);
            if (val > n) return false;

            if (nums[val] < 0) {
                if (val < n || dup) return false;
                dup = true;
                continue;
            }

            nums[val] = -nums[val];
        }

        return true;
    }
};