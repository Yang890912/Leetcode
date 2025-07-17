class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0;
        int curPos = 0;

        while (curPos + 2 < nums.size()) {
            if (nums[curPos] == 1) {
                curPos++;
                continue;
            }
            else {
                nums[curPos] ^= 1;
                nums[curPos + 1] ^= 1;
                nums[curPos + 2] ^= 1;
                curPos++;
                res++;
            }
        }

        return (nums[curPos] == 0 || nums[curPos + 1] == 0) ? -1 : res;
    }
};