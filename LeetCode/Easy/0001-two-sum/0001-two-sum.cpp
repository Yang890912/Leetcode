class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, stack<int>> val2Pos;
        
        for (int i = 0; i < nums.size(); i++) val2Pos[nums[i]].push(i);

        sort(nums.begin(), nums.end());

        int i = 0;
        int j = nums.size() - 1;
        while (i < j) {
            if (nums[i] + nums[j] > target) j--;
            else if (nums[i] + nums[j] < target) i++;
            else {
                res.push_back(val2Pos[nums[i]].top());
                val2Pos[nums[i]].pop();
                res.push_back(val2Pos[nums[j]].top());
                break;
            }
        }
        
        return res;
    }
};