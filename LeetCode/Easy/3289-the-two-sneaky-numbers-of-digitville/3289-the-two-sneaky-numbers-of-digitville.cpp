class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> res;
        vector<int> count(101, 0);

        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
            if (count[nums[i]] >= 2) res.push_back(nums[i]);
        }

        return res;
    }
};