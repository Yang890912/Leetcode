class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int first = nums[0];
        int second = INT_MAX, third = INT_MAX;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < second) second = nums[i];
            if (second < third) swap(second, third);
        }

        return first + second + third;
    }
};