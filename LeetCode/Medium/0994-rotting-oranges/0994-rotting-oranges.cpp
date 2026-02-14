class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        const vector<vector<int>> DIR = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        int numOrange = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
                else if (grid[i][j] == 1) numOrange++;
            }
        }

        if (numOrange == 0) return 0;

        int res = -1;
        while (!q.empty()) {
            int size = q.size();
            res++;

            while (size--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (auto& d : DIR) {
                    int nx = x + d[0];
                    int ny = y + d[1];

                    if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny] || grid[nx][ny] != 1) continue;

                    numOrange--;
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        if (numOrange > 0) return -1;

        return res;
    }
};