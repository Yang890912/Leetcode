class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0) return 0;

        sort(nums.begin(), nums.end());

        int n = nums.size();
        int left = 0, right = nums[n - 1] - nums[0];
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int i = 0, count = 0;
            while (i + 1 < n) {
                if (nums[i + 1] - nums[i] <= mid) {
                    count++;
                    i++;
                }
                i++;
            }

            if (count >= p) right = mid - 1;
            else left = mid + 1;
        }

        return left;
    }
};