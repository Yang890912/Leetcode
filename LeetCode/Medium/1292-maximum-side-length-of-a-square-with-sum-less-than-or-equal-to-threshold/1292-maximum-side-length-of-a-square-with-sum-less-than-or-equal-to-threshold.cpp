class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> prefixSum = mat;

        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                prefixSum[i][j] += prefixSum[i][j - 1];
            }
        }

        for (int j = 0; j < n; j++) {
            for (int i = 1; i < m; i++) {
                prefixSum[i][j] += prefixSum[i - 1][j];
            }
        }

        int l = 1, r = min(m, n);
        while (l <= r) {
            int mid = (l + r) / 2;
            if (isValid(prefixSum, threshold, mid)) l = mid + 1;
            else r = mid - 1;
        }

        return r;
    }

    bool isValid(vector<vector<int>> prefixSum, int threshold, int length) {
        for (int i = length - 1; i < prefixSum.size(); i++) {
            for (int j = length - 1; j < prefixSum[0].size(); j++) {
                int x1 = i - length + 1;
                int y1 = j - length + 1;

                int sum = prefixSum[i][j] 
                        - (x1 == 0 ? 0 : prefixSum[x1 - 1][j]) 
                        - (y1 == 0 ? 0 : prefixSum[i][y1 - 1]) 
                        + (x1 == 0 || y1 == 0 ? 0 : prefixSum[x1 - 1][y1 - 1]);

                if (sum <= threshold) return true;
            }
        }

        return false;
    }
};