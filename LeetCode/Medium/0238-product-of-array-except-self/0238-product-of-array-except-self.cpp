class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int numZeros = 0;
        vector<int> answer(nums.size(), 0);

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                numZeros++;
                continue;
            }
            product *= nums[i];
        }

        if (numZeros >= 2) return answer;

        for (int i = 0; i < nums.size(); i++) {
            if (numZeros == 1) {
                if (nums[i] == 0) answer[i] = product;
                else answer[i] = 0;
            }
            else answer[i] = product / nums[i];
        }

        return answer;
    }
};