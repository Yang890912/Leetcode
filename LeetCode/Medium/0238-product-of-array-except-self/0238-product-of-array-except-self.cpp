class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        long long product = 1;
        vector<int> res(n, 0);

        int numZero = 0;
        for (int& num : nums) {
            if (num == 0) numZero++;
            else product *= num;
        }
        
        if (numZero > 1) return res;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) res[i] = product;
            else if (numZero > 0) res[i] = 0;
            else res[i] = product / nums[i];
        }

        return res;
    }
};