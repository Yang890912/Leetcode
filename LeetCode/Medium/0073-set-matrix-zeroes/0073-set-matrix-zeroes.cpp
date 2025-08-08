class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rows;
        set<int> columns;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    columns.insert(j);
                }
            }    
        }

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) continue;

                if (rows.count(i)) matrix[i][j] = 0;
                else if (columns.count(j)) matrix[i][j] = 0;
            }    
        }
    }
};