class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;

        int prev0 = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if (prev0 == -1) prev0 = i;
                res += (i - prev0 + 1);
            }
            else prev0 = -1;
        }

        return res;
    }
};