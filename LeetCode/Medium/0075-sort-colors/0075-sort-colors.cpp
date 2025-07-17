class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int red = 0, blue = nums.size() - 1;

        while (left <= right) {
            if (nums[left] == 0) swap(nums[left++], nums[red++]);
            else if (nums[left] == 2) swap(nums[left], nums[blue--]), right--;
            else if (nums[right] == 2) swap(nums[right--], nums[blue--]);
            else if (nums[right] == 0) swap(nums[right], nums[red++]), left++;
            else if (nums[left] == 1) left++;
            else right--;
        }
    }
};