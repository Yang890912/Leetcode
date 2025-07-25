class Solution {
public:
    int maxSum(vector<int>& nums) {
        int res = INT_MIN;

        vector<int> newNums;
        unordered_set<int> us;
        for (int num : nums) {
            if (us.count(num) == 0) {
                us.insert(num);
                newNums.push_back(num);
            }
        }

        int currSum = 0;
        for (int i = 0; i < newNums.size(); i++) {
            if (i == 0) currSum = newNums[i];
            else if (newNums[i] < 0 && newNums[i] > currSum) currSum = newNums[i];
            else if (newNums[i] >= 0 && currSum < 0) currSum = newNums[i];
            else if (newNums[i] >= 0) currSum += newNums[i];
            
            res = max(res, currSum);
        }

        return res;
    }
};