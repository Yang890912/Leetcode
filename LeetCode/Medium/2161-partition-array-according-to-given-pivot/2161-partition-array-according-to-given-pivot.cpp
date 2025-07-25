class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> res(nums.size(), pivot);
        
        int i = 0, left = 0;
        int j = nums.size() - 1, right = nums.size() - 1;
        while (i < nums.size() && j >= 0) {
            if (nums[i] < pivot) res[left++] = nums[i];
            if (nums[j] > pivot) res[right--] = nums[j];
            i++;
            j--;
        }

        return res;
    }
};