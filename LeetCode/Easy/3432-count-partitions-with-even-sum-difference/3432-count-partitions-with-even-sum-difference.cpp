class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int res = 0;
        int sum = 0, _sum = 0;

        for (int num : nums) sum += num;

        for (int i = 0; i < nums.size() - 1; i++) {
            _sum += nums[i];
            if ((sum - _sum - _sum) % 2 == 0) res++;
        }

        return res;
    }
};