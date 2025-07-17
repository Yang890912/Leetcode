class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int minutes = 0;
        queue<vector<int>> q;
        vector<pair<int, int>> DIR = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) 
                    q.push({i, j, 0});
            }
        }

        while (!q.empty()) {
            int x = q.front()[0];
            int y = q.front()[1];
            int level = q.front()[2];
            
            q.pop();
            if (level >= minutes) minutes = level;

            for (int i = 0; i < DIR.size(); i++) {
                int nx = x + DIR[i].first;
                int ny = y + DIR[i].second;
                if (nx < m && nx >= 0 && ny < n && ny >= 0 && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    q.push({nx, ny, level + 1});
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) return -1;
            }
        }

        return minutes;
    }
};