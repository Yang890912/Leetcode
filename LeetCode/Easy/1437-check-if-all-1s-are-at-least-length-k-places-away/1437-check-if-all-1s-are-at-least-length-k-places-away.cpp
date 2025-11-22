class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int i = 0;
        int prev = -1;

        while (i < nums.size()) {
            if (nums[i] == 1) {
                if (prev == -1) prev = i;
                else {
                    if (i - prev - 1 < k) return false;
                    else prev = i;
                }
            }
            i++;
        }

        return true;
    }
};