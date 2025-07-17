class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long res = 0;
        int maxNum = 0;

        for (int i = 0; i < nums.size(); i++) {
            maxNum = max(maxNum, nums[i]);
        }

        int left = 0, right = 0;
        int countsOfMax = 0;

        while (left < nums.size() && right < nums.size()) {
            if (nums[right] == maxNum) countsOfMax++;

            while (countsOfMax >= k) {
                res += (nums.size() - right);
                if (nums[left] == maxNum) countsOfMax--;
                left++;
            }
            
            right++;
        }

        return res;
    }
};