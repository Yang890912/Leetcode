class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;

        for (int i = 1; i < 10; i++)
            dfs(res, i, i + 1, low, high);

        sort(res.begin(), res.end());

        return res;
    }

    void dfs(vector<int>& res, int curr, int dig, int low, int high) {
        if (curr > high) return;

        if (curr >= low) 
            res.push_back(curr);

        if (dig < 10) 
            dfs(res, curr * 10 + dig, dig + 1, low, high);
    }
};