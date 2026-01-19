class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int k = min(m, n); k >= 1; k--) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (isValid(grid, i, j, k, m, n)) return k;
                }
            }
        }

        return 1;
    }

    bool isValid(vector<vector<int>>& grid, int x, int y, int length, int m, int n) {
        if (x + length > m || y + length > n) return false;

        int sum = 0;
        for (int j = y; j < y + length; j++) sum += grid[x][j];

        int _sum = 0;
        for (int i = x + 1; i < x + length; i++) {
            _sum = 0;
            for (int j = y; j < y + length; j++) _sum += grid[i][j];
            
            if (_sum != sum) return false;
        }

        for (int j = y; j < y + length; j++) {
            _sum = 0;
            for (int i = x; i < x + length; i++) _sum += grid[i][j];
            
            if (_sum != sum) return false;
        }

        _sum = 0;
        for (int k = 0; k < length; k++) {
            _sum += grid[x + k][y + k];
        }
        if (_sum != sum) return false;

        _sum = 0;
        for (int k = 0; k < length; k++) {
            _sum += grid[x + length - 1 - k][y + k];
        }
        if (_sum != sum) return false;

        return true;
    }
                    
};