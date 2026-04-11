class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int, vector<int>> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);    
        }

        int res = INT_MAX;
        for (auto& it : mp) {
            vector<int> v = it.second;
            if (v.size() < 3) continue;
            for (int j = 0; j < v.size() - 2; j++) {
                res = min(res, 2 * abs(v[j] - v[j + 2]));
            }
        }

        return (res == INT_MAX) ? -1 : res;
    }
};