class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        int res = INT_MAX;
        
        for (int i = start; i < n; i++) {
            if (nums[i] == target) {
                res = abs(i - start);
                break;
            }
        }

        for (int i = start; i >= 0; i--) {
            if (nums[i] == target) {
                res = min(res, abs(i - start));
                break;
            }
        }

        return res;
    }
};