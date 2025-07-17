class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int numOfIslands = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(grid, visited, i, j);
                    numOfIslands++;
                }
            }
        }
        
        return numOfIslands;
    }

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
        visited[x][y] = true;
        if (x - 1 >= 0 && grid[x - 1][y] == '1' && !visited[x - 1][y]) 
            dfs(grid, visited, x - 1, y);
        if (x + 1 < grid.size() && grid[x + 1][y] == '1' && !visited[x + 1][y]) 
            dfs(grid, visited, x + 1, y);
        if (y - 1 >= 0 && grid[x][y - 1] == '1' && !visited[x][y - 1]) 
            dfs(grid, visited, x, y - 1);
        if (y + 1 < grid[0].size() && grid[x][y + 1] == '1' && !visited[x][y + 1]) 
            dfs(grid, visited, x, y + 1);
    }
};