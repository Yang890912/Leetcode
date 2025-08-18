class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), -1));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if(dfs(board, i, j, visited, word, 0)) 
                    return true;
            }
        }

        return false;
    }

    bool dfs(const vector<vector<char>>& board, 
            int i, int j,
            vector<vector<int>>& visited, 
            string word, 
            int idx) {
        
        if (idx == word.size()) 
            return true;

        if (i < 0 || i >= board.size() || 
            j < 0 || j >= board[0].size() ||
            board[i][j] != word[idx] || 
            visited[i][j] == 1) 
            return false;

        visited[i][j] = 1;
        bool found =    dfs(board, i + 1, j, visited, word, idx + 1) ||
                        dfs(board, i - 1, j, visited, word, idx + 1) ||
                        dfs(board, i, j + 1, visited, word, idx + 1) ||
                        dfs(board, i, j - 1, visited, word, idx + 1);
        visited[i][j] = -1;

        return found;
    }
};