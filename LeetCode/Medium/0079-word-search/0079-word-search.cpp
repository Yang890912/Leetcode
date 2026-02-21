class Solution {
public:
    const vector<vector<int>> DIR = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != word[0]) continue;

                vector<vector<bool>> visited(m, vector<bool>(n, false));
                if (dfs(board, i, j, visited, word, 0)) return true;
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, int x, int y, vector<vector<bool>>& visited, string& word, int pos) {
        visited[x][y] = true;
        
        if (pos == word.size() - 1) return true;

        for (auto& d : DIR) {
            int nx = x + d[0];
            int ny = y + d[1];

            if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size() 
            || visited[nx][ny] || board[nx][ny] != word[pos + 1]) continue;

            if (dfs(board, nx, ny, visited, word, pos + 1)) return true;

            visited[nx][ny] = false;
        }

        return false;
    }
};  