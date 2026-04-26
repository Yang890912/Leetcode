class Solution {
public:
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j])
                    if (bfs(grid, visited, i, j)) return true;
            }
        }

        return false;
    }

    bool bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
        queue<vector<int>> q;
        q.push({x, y, -1, -1});
        visited[x][y] = true;

        while (!q.empty()) {
            int cx = q.front()[0], cy = q.front()[1];
            int px = q.front()[2], py = q.front()[3];
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size())
                    continue;
                if (nx == px && ny == py)
                    continue;
                
                if (grid[nx][ny] == grid[cx][cy]) {
                    if (!visited[nx][ny]) {
                        visited[nx][ny] = true; 
                        q.push({nx, ny, cx, cy});
                    }
                    else return true;
                }
            }
        }

        return false;
    }
};