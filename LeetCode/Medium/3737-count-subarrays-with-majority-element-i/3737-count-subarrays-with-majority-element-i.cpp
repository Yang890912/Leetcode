class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> count(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            count[i] = count[i - 1] + ((nums[i - 1] == target) ? 1 : 0);
        }

        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                if (2 * (count[j] - count[i - 1]) > (j - i + 1)) res++;
            }
        }

        return res;
    }
};