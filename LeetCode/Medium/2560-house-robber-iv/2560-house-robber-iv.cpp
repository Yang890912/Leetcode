class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int left = 1;
        int right = 1e9;

        while (left <= right) {
            int mid = (left + right) / 2;
            bool canSteal = lessGuess(nums, mid, k);
            if (canSteal) right = mid - 1;
            else left = mid + 1;
        }

        return left;

    }

    bool lessGuess(vector<int>& nums, int guess, int k) {
        int i = 0;
        int count = 0;
        while (i < nums.size()) {
            if (nums[i] <= guess) {
                count++;
                i++;
            }
            i++;

            if (count >= k) return true;   
        }
        return false;
    }
};