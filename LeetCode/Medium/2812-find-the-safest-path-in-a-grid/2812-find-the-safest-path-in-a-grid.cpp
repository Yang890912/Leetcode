class Solution {
public:
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return 0;

        markDis(grid, n);

        int l = 0, r = 2 * n - 2;
        int res = r;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (bfs(grid, n, mid)) {
                res = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        return res;
    }

    void markDis(vector<vector<int>>& grid, int n) {
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                q.push({i, j});
                grid[i][j] = 0;
                visited[i][j] = true;
            }
        }
        
        int level = 1;
        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                int x = q.front().first, y = q.front().second;
                q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir], ny = y + dy[dir];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n || visited[nx][ny])
                        continue;
                    grid[nx][ny] = level;
                    visited[nx][ny] = true; 
                    q.push({nx, ny});
                }
            }
            level++;
        }
    }


    bool bfs(vector<vector<int>>& grid, int n, int dis) {
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        if (grid[0][0] < dis) return false;

        q.push({0, 0});
        visited[0][0] = true;
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();

            if (x == n - 1 && y == n - 1) return true;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n || grid[nx][ny] < dis || visited[nx][ny])
                    continue;

                visited[nx][ny] = true;
                q.push({nx, ny});

                if (nx == n - 1 && ny == n - 1) return true;
            }
        }

        return false;
    }


};