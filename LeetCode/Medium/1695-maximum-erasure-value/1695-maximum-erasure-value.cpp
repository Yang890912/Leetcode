class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxScore = 0;

        unordered_set<int> us;
        int currScore = 0;
        int i = 0, j = 0;
        while (i < n) {
            if (!us.count(nums[i])) {
                us.insert(nums[i]);
                currScore += nums[i];
                maxScore = max(maxScore, currScore);
                i++;
            }
            else {
                while (us.count(nums[i])) {
                    us.erase(nums[j]);
                    currScore -= nums[j];
                    j++;
                }
            }
        }

        return maxScore;
    }
};