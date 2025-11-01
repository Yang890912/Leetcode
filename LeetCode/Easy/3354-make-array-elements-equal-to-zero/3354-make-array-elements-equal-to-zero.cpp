class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n, 0);
        vector<int> suffixSum(n, 0);

        prefixSum[0] = nums[0];
        suffixSum[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) prefixSum[i] = nums[i] + prefixSum[i - 1];
        for (int i = n - 2; i >= 0; i--) suffixSum[i] = nums[i] + suffixSum[i + 1];

        int res = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0 && prefixSum[i] == suffixSum[i]) res += 2;
        }

        return res;
    }
};