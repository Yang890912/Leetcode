class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        for (int i = 0; i < numRows; i++) {
            if (i == 0) res.push_back({1});
            else if (i == 1) res.push_back({1, 1});
            else {
                vector<int> row;
                int n = res[i - 1].size();
                row.push_back(1);
                for (int j = 1; j < n; j++) {
                    row.push_back(res[i - 1][j - 1] + res[i - 1][j]);
                }
                row.push_back(1);
                res.push_back(row);
            }
        }

        return res;
    }
};