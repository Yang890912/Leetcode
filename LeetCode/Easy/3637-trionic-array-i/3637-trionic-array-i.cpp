class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int pos1 = 0;
        int pos2 = n - 1;

        for (int i = pos1; i < n - 1; i++) {
            if (nums[i + 1] > nums[i]) pos1++;
            else break;
        }

        for (int i = pos2; i > 0; i--) {
            if (nums[i - 1] < nums[i]) pos2--;
            else break;
        }

        if (pos2 <= pos1 || pos1 == 0 || pos2 == n - 1) return false;

        for (int i = pos1; i < pos2; i++) {
            if (nums[i] <= nums[i + 1]) return false;
        }

        return true;
    }
};