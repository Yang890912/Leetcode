class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        int m = queries.size();

        for (int i = 0; i < m; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            int v = queries[i][3];
            for (int j = l; j <= r; j += k) {
                nums[j] = ((long long)nums[j] * v) % MOD;
            }
        }
        
        int res = 0;
        for (int num : nums) 
            res ^= num;
        
        return res;
    }
};