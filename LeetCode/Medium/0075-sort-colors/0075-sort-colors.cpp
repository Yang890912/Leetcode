class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        selectSort(nums, start, 0);
        selectSort(nums, start, 1);
        selectSort(nums, start, 2);
    }

    void selectSort(vector<int>& nums, int& start, int color) {
        for (int i = start; i < nums.size(); i++) {
            if (nums[i] == color) {
                swap(nums[i], nums[start]);
                start++;
            }
        }
    }
};