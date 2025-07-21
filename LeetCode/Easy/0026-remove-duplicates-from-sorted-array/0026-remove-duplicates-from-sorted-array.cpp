class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr = nums[0];
        int res = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > curr) {
                curr = nums[i];
                nums[res++] = nums[i]; 
            }
        }
        return res;
    }
};