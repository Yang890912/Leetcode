class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int res = 0;

        for (int i = 0; i < n; i++) {
            int currLen = 0;
            unordered_set<int> us;
            vector<int> count(2, 0);
            for (int j = i; j < n; j++) {
                currLen++;
                if (!us.count(nums[j])) count[nums[j] & 1]++;
                us.insert(nums[j]);

                if (count[0] == count[1]) res = max(res, currLen);
            }
        }

        return res;
    }
};