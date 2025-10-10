class Solution {
public:
    vector<vector<int>> DIR = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> canFlowToPacific(m, vector<bool>(n, false));
        vector<vector<bool>> canFlowToAtlantic(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) dfs(i, 0, canFlowToPacific, heights);
        for (int j = 0; j < n; j++) dfs(0, j, canFlowToPacific, heights);
        for (int i = 0; i < m; i++) dfs(i, n - 1, canFlowToAtlantic, heights);
        for (int j = 0; j < n; j++) dfs(m - 1, j, canFlowToAtlantic, heights);

        vector<vector<int>> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (canFlowToPacific[i][j] && canFlowToAtlantic[i][j]) res.push_back({i, j});
            }
        }

        return res;
    }

    void dfs(int x, int y, vector<vector<bool>>& flow, vector<vector<int>>& heights) {
        flow[x][y] = true;
        for (auto d : DIR) {
            int nx = x + d[0];
            int ny = y + d[1];

            if (nx < 0 || nx >= heights.size()) continue;
            if (ny < 0 || ny >= heights[0].size()) continue;
            if (flow[nx][ny]) continue;
            if (heights[nx][ny] >= heights[x][y]) dfs(nx, ny, flow, heights);
        }
    }
};