class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int res = INT_MAX;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            string s = to_string(nums[i]);
            reverse(s.begin(), s.end());
            int rev = stoi(s);

            if (mp.count(nums[i])) {
                res = min(res, i - mp[nums[i]]);
            }

            mp[rev] = i;
        }

        return (res == INT_MAX) ? -1 : res;
    }
};