class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = 0;
        
        int maxVal = 0;
        for (int num : nums) {
            maxVal = max(maxVal, num);
        }

        int currRes = 0;
        for (int num : nums) {
            if (num == maxVal) {
                currRes++;
                res = max(currRes, res);
            }
            else currRes = 0;
        }

        return res;
    }
};