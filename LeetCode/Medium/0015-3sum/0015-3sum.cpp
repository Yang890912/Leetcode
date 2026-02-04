class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;

        for (int i = 0; i < n; i++) {
            if (i >= 1 && nums[i] == nums[i - 1]) continue;

            int target = -(nums[i]);
            int l = i + 1, r = n - 1; 
            while (l < r) {
                if (l > i + 1 && nums[l - 1] == nums[l]) l++;
                else if (r < n - 1 && nums[r + 1] == nums[r]) r--;
                else if (nums[l] + nums[r] < target) l++;
                else if (nums[l] + nums[r] > target) r--;
                else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                }
            }
        }

        return res;
    }
};