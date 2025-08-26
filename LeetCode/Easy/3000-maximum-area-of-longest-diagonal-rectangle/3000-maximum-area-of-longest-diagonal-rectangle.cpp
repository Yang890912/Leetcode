class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        vector<vector<double>> diagAndArea(dimensions.size());
        
        for (int i = 0; i < dimensions.size(); i++) {
            diagAndArea[i].push_back(sqrt(dimensions[i][0] * dimensions[i][0] + dimensions[i][1] * dimensions[i][1]));
            diagAndArea[i].push_back(dimensions[i][0] * dimensions[i][1]);
        }

        sort(diagAndArea.rbegin(), diagAndArea.rend());

        return diagAndArea[0][1];
    }
};