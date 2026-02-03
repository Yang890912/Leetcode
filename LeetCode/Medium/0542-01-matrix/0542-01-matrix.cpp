class Solution {
    const vector<vector<int>> DIR = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> distance(m, vector<int>(n, -1));
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        queue<vector<int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != 0) continue;

                distance[i][j] = 0;
                visited[i][j] = true;
                q.push({i, j, 0});
            }
        }

        while (!q.empty()) {
            int x = q.front()[0], y = q.front()[1];
            int dist = q.front()[2];
            q.pop();

            for (const vector<int>& d : DIR) {
                int nx = x + d[0], ny = y + d[1];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny]) continue;

                distance[nx][ny] = dist + 1;
                visited[nx][ny] = true;
                q.push({nx, ny, distance[nx][ny]});
            }
        }

        return distance;
    }
};