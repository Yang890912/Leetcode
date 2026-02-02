class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> um;
        
        for (int i = 0; i < nums.size(); i++) {
            um[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int t = target - nums[i];
            if (!um.count(t) || um[t] == i) continue;

            res.push_back(i);
            res.push_back(um[t]);
            break;
        }

        return res;
    }
};