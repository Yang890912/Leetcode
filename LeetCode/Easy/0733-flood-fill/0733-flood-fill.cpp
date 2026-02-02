class Solution {
public:
    const vector<vector<int>> DIR = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        dfs(m, n, image, visited, sr, sc, image[sr][sc], color);

        return image;
    }

    void dfs(int m, int n, vector<vector<int>>& image, vector<vector<bool>>& visited, int x, int y, int from, int to) {
        visited[x][y] = true;
        image[x][y] = to;
  
        for (int i = 0; i < DIR.size(); i++) {
            int nx = x + DIR[i][0];
            int ny = y + DIR[i][1];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || image[nx][ny] != from || visited[nx][ny]) continue;
            dfs(m, n, image, visited, nx, ny, from, to);
        }

        return;
    }
};