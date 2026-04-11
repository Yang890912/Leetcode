class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        vector<vector<int>> freq(100001, vector<int>());
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]].push_back(i);    
        }

        int res = INT_MAX;
        for (int i = 1; i < 100001; i++) {
            if (freq[i].size() < 3) continue;
            for (int j = 0; j < freq[i].size() - 2; j++) {
                res = min(res, 
                        abs(freq[i][j] - freq[i][j + 1]) + abs(freq[i][j + 1] - freq[i][j + 2]) + abs(freq[i][j] - freq[i][j + 2]));
            }
        }

        return (res == INT_MAX) ? -1 : res;
    }
};