class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> maxRight(m, -1);

        for (int i = 0; i < m; i++) {
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 1) {
                    maxRight[i] = j;
                    break;
                }
            }
        }

        int res = 0;
        for (int i = 0; i < m; i++) {
            if (maxRight[i] <= i) continue;
            
            int j = i;
            while (j < n && maxRight[j] > i) res++, j++;
            if (j == n) return -1;
            
            while (j > i) {
                swap(maxRight[j - 1], maxRight[j]);
                j--;
            }
        }

        return res;
    }
};