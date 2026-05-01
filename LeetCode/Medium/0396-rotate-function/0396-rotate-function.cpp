class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int curr = 0;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            curr += i * nums[i];
            sum += nums[i];
        }

        res = curr;

        for (int j = n - 1; j >= 0; j--) {
            curr += sum;
            curr -= n * nums[j];
            res = max(res, curr);
        }

        return res;   
    }
};