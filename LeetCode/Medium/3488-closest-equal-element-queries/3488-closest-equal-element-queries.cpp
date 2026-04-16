class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> res;
        for (int q : queries) {
            vector<int>& v = mp[nums[q]];
            if (v.size() == 1) {
                res.push_back(-1);
                continue;
            }

            int pos = lower_bound(v.begin(), v.end(), q) - v.begin();
            int cur = INT_MAX;

            int l = abs(v[(pos + 1) % v.size()] - q);
            int r = abs(v[(pos - 1 + v.size()) % v.size()] - q);

            cur = min(cur, min(l, n - l));
            cur = min(cur, min(r, n - r));
            res.push_back(cur);
        }

        return res;
    }
};