class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long res = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        int numOfNegs = 0;
        long long currMin = 100000;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res += abs(matrix[i][j]);
                if (matrix[i][j] < 0) numOfNegs++;
                if (abs(matrix[i][j]) < currMin) currMin = abs(matrix[i][j]);
            }
        }

        if (numOfNegs % 2 == 1) res -= 2 * currMin;

        return res;
    }
};