class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int res = 0;
        
        int n = nums.size();
        vector<int> nearLeft(n, 0), nearRight(n, 0);
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] == nums[i - 1]) nearLeft[i] = nearLeft[i - 1];
            else nearLeft[i] = nums[i - 1];
        }
        for (int i = n - 2; i >= 1; i--) {
            if (nums[i] == nums[i + 1]) nearRight[i] = nearRight[i + 1];
            else nearRight[i] = nums[i + 1];
        }

        for (int i = 1; i < n - 1; i++) {
            if (nearLeft[i] == 0 || nearRight[i] == 0 || nums[i] == nums[i - 1]) continue;
            else if (nums[i] > nearLeft[i] && nums[i] > nearRight[i]) res++;
            else if (nums[i] < nearLeft[i] && nums[i] < nearRight[i]) res++;
        }

        return res;
    }
};