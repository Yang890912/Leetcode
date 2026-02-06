class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        int res = n;

        if (n == 1) return 0;
        sort(nums.begin(), nums.end());

        int l = 0, r = 0;
        while (l < n && r < n) {
            if (nums[r] <= 1LL * k * nums[l]) {
                res = min(res, n - (r - l + 1));
                r++;
            }
            else {
                l++;
                // r = max(r, l);
            }
        }
        
        return res;
    }
};