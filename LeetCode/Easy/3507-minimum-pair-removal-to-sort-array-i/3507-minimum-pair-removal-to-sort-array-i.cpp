class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int res = 0;

        while (!isNonDec(nums)) {
            int minSum = INT_MAX;
            int pos = -1;

            for (int i = 0; i < nums.size() - 1; i++) {
                if (nums[i] + nums[i + 1] < minSum) {
                    minSum = nums[i] + nums[i + 1];
                    pos = i;
                }
            }

            vector<int> _nums;
            for (int i = 0; i < nums.size(); i++) {
                if (pos == i) {
                    _nums.push_back(nums[i] + nums[i + 1]);
                    i++;
                }
                else {
                    _nums.push_back(nums[i]);
                }
            }

            nums = _nums;
            res++;
        }

        return res;
    }

    bool isNonDec(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] < nums[i]) return false;
        }
        return true;
    }
};