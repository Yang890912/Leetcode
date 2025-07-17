class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int left = 0;
        int right = queries.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            vector<int> prefixSum(nums.size() + 1, 0);

            for (int i = 0; i <= mid; i++) {
                prefixSum[queries[i][0]] += queries[i][2];
                prefixSum[queries[i][1] + 1] -= queries[i][2];
            }

            for (int i = 1; i < nums.size(); i++) {
                prefixSum[i] += prefixSum[i - 1];
            }
            
            bool canZero = true;
            for (int i = 0; i < nums.size(); i++) {
                if (prefixSum[i] < nums[i]) {
                    canZero = false;
                    break;
                }
            }

            if (canZero) right = mid - 1;
            else left = mid + 1;
        }

        bool allZero = true;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                allZero = false;
                break;
            }
        }

        if (allZero) return 0;

        return (left + 1) > queries.size() ? -1 : left + 1;
    }
};