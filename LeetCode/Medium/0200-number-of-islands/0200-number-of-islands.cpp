class Solution {
public:
    const vector<vector<int>> DIR = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] || grid[i][j] == '0') continue;
                dfs(grid, visited, m, n, i, j);
                res++;
            }
        }

        return res;
    }

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int m, int n, int x, int y) {
        visited[x][y] = true;

        for (auto& d : DIR) {
            int nx = x + d[0];
            int ny = y + d[1];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny] || grid[nx][ny] == '0') continue;
            dfs(grid, visited, m, n, nx, ny);
        }
    }
};