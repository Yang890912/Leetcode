class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> prefixSum(nums.size(), 0);

        for (auto query : queries) {
            prefixSum[query[0]]++;
            if (query[1] + 1 < nums.size()) prefixSum[query[1] + 1]--;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0) prefixSum[i] = prefixSum[i] + prefixSum[i - 1];
            if (prefixSum[i] < nums[i]) return false;
        }

        return true;
    }
};