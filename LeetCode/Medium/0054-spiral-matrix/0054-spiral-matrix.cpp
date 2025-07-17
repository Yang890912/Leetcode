class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> res;
        int left = 0, right = n - 1, top = 0, down = m - 1;

        while (top <= down && left <= right) {
            for (int i = left; i <= right; i++) {
                res.push_back(matrix[top][i]);
            }
            top++;

            for (int i = top; i <= down; i++) {
                res.push_back(matrix[i][right]);
            }
            right--;

            if (top <= down) {
                for (int i = right; i >= left; i--) {
                    res.push_back(matrix[down][i]);
                }   
                down--;
            }

            if (left <= right) {
                for (int i = down; i >= top; i--) {
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return res;
    }
};