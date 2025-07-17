class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int numOfOdd = 0;
        int numOfEven = 0;
        int currLen = 1;
        int prevNum = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) numOfEven++;
            else numOfOdd++;

            if (i >= 1 && nums[i] % 2 != prevNum % 2) {
                currLen++;
                prevNum = nums[i];
            }
        }

        return max(max(numOfOdd, numOfEven), currLen);
    }
};