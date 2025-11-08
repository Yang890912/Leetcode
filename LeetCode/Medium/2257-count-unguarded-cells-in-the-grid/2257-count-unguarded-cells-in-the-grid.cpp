class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> guarded(m, vector<int>(n, 0));
        set<vector<int>> found;
        
        for (auto wall : walls) {
            guarded[wall[0]][wall[1]] = 2;
            found.insert({wall[0], wall[1]});
        }

        for (auto guard : guards) {
            guarded[guard[0]][guard[1]] = 3;
            found.insert({guard[0], guard[1]});
        }

        for (auto guard : guards) {
            int x = guard[0];
            int y = guard[1];

            check(m, n, x + 1, y, "r", guarded, found);
            check(m, n, x, y + 1, "u", guarded, found);
            check(m, n, x - 1, y, "l", guarded, found);
            check(m, n, x, y - 1, "d", guarded, found);
        }

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (guarded[i][j] == 0) res++;
            }
        }

        return res;
    }

    void check(int m, int n, int x, int y, string dir, vector<vector<int>>& guarded, set<vector<int>>& found) {
        if (x < 0 || x >= m || y < 0 || y >= n) return;
        if (found.count({x, y})) return;
        
        guarded[x][y] = 1;
  
        if (dir == "r") check(m, n, x + 1, y, dir, guarded, found);
        else if (dir == "u") check(m, n, x, y + 1, dir, guarded, found);
        else if (dir == "l") check(m, n, x - 1, y, dir, guarded, found);
        else if (dir == "d") check(m, n, x, y - 1, dir, guarded, found);
    }
};