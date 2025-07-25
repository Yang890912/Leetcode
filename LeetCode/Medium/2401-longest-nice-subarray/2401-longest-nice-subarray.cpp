class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int longest = 1;
        int left = 0;
        int right = 0;
        int usedBit = 0;

        while (right < nums.size()) {
            if (left == right) {
                usedBit = nums[left];
                right++;
            }
            else if ((usedBit & nums[right]) == 0) {
                usedBit |= nums[right];
                longest = max(longest, right - left + 1);
                right++;
            }
            else {
                usedBit ^= nums[left];
                left++;
            }
        }

        return longest;
    }
};