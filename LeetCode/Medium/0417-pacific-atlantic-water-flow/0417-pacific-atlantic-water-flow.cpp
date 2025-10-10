class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> canFlowToPacific(m, vector<bool>(n, false));
        vector<vector<bool>> canFlowToAtlantic(m, vector<bool>(n, false));
       
        bool updated = true;
        while (updated) {
            updated = false;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (!canFlowToPacific[i][j]) {
                        if (i == 0) canFlowToPacific[i][j] = true, updated = true;
                        if (j == 0) canFlowToPacific[i][j] = true, updated = true;
                        if ((i - 1 >= 0 && heights[i - 1][j] <= heights[i][j] && canFlowToPacific[i - 1][j]) ||
                            (j - 1 >= 0 && heights[i][j - 1] <= heights[i][j] && canFlowToPacific[i][j - 1]) ||
                            (i + 1 < m && heights[i + 1][j] <= heights[i][j] && canFlowToPacific[i + 1][j]) ||
                            (j + 1 < n &&heights[i][j + 1] <= heights[i][j] && canFlowToPacific[i][j + 1])) {
                            canFlowToPacific[i][j] = true;
                            updated = true;
                        }
                    }

                    if (!canFlowToAtlantic[i][j]) {
                        if (i == m - 1) canFlowToAtlantic[i][j] = true, updated = true;
                        if (j == n - 1) canFlowToAtlantic[i][j] = true, updated = true;
                        if ((i - 1 >= 0 && heights[i - 1][j] <= heights[i][j] && canFlowToAtlantic[i - 1][j]) ||
                            (j - 1 >= 0 && heights[i][j - 1] <= heights[i][j] && canFlowToAtlantic[i][j - 1]) ||
                            (i + 1 < m && heights[i + 1][j] <= heights[i][j] && canFlowToAtlantic[i + 1][j]) ||
                            (j + 1 < n &&heights[i][j + 1] <= heights[i][j] && canFlowToAtlantic[i][j + 1])) {
                            canFlowToAtlantic[i][j] = true;
                            updated = true;
                        }
                    }
                }
            }
        }

        vector<vector<int>> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (canFlowToPacific[i][j] && canFlowToAtlantic[i][j])
                    res.push_back({i, j});
            }
        }

        return res;
    }
};