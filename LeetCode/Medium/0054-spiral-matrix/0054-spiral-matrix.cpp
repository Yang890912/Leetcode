class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const vector<vector<int>> DIR = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        const int m = matrix.size();
        const int n = matrix[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<int> res;
        
        int x = 0, y = 0, turn = 0;
        while (true) {
            res.push_back(matrix[x][y]);
            visited[x][y] = true;
            
            int nx = x + DIR[turn][0];
            int ny = y + DIR[turn][1];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny]) {
                turn++;
                turn %= 4;
                nx = x + DIR[turn][0];
                ny = y + DIR[turn][1];
            }

            if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny]) break;

            x = nx;
            y = ny;
        }

        return res;
    }
};