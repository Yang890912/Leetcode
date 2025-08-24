class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int longest = 0;
        int prevLength = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) count++;
            else {
                if (count == 0) prevLength = 0;
                else {
                    longest = max(longest, count + prevLength);
                    prevLength = count;
                    count = 0;
                }
            }
        }

        longest = max(longest, count - 1);
        if (prevLength > 0 && count > 0) 
            longest = max(longest, count + prevLength);

        return longest;
    }
};