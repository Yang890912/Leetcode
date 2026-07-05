class Solution {
public:
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> copy = grid;
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) q.push({i, j});
            }
        }

        int l = 1, r = 2 * n - 2;
        while (l <= r) {
            int mid = (l + r) / 2;
            fill(grid, q, n, mid - 1);
            if (bfs(grid, n)) l = mid + 1;
            else r = mid - 1;
            grid = copy;
        }

        return r;
    }

    void fill(vector<vector<int>>& grid, queue<pair<int, int>> q, int n, int dis) {
        while (!q.empty() && dis > 0) {
            int size = q.size();
            while (size--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                for (int i = 0; i < 4; i++) {
                    int _x = x + dx[i];
                    int _y = y + dy[i];
                    if (_x < 0 || _y < 0 || _x >= n || _y >= n || grid[_x][_y] == 1)
                        continue;
                    grid[_x][_y] = 1;  
                    q.push({_x, _y});
                }
            }

            dis--;
        }
    }


    bool bfs(vector<vector<int>>& grid, int n) {
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return false;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == n - 1 && y == n - 1) return true;

            for (int i = 0; i < 4; i++) {
                int _x = x + dx[i];
                int _y = y + dy[i];
                if (_x < 0 || _y < 0 || _x >= n || _y >= n || grid[_x][_y] == 1 || visited[_x][_y])
                    continue;
                if (_x == n - 1 && _y == n - 1) return true;
                visited[_x][_y] = true;  
                q.push({_x, _y});
            }
        }

        return false;
    }


};