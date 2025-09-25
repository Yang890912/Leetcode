class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> pathSum(triangle.size(), 20000);

        pathSum[0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); i++) {
            vector<int> tmp = pathSum;
            for (int j = 0; j < triangle[i].size(); j++) {
                tmp[j] = min(pathSum[j] + triangle[i][j], 
                             pathSum[max(j - 1, 0)] + triangle[i][j]);
            }
            pathSum = tmp;
        }

        sort(pathSum.begin(), pathSum.end());

        return pathSum[0];
    }
};