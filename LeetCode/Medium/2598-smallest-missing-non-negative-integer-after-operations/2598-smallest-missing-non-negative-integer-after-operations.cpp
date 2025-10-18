class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> cnt(value, 0);

        for (int i = 0; i < nums.size(); i++) {
            int r = ((nums[i] % value) + value) % value;
            cnt[r]++;
        }

        int res = 0;
        while(true) {
            int r = res % value;
            if (cnt[r] <= 0) break;

            cnt[r]--;
            res++;
        }

        return res;
    }
};