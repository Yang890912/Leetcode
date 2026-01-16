class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        for (int i = 0; i < points.size() - 1; i++) {
            int xDiff = abs(points[i][0] - points[i + 1][0]);
            int yDiff = abs(points[i][1] - points[i + 1][1]);
            res += xDiff + yDiff - min(xDiff, yDiff);
        }

        return res;
    }
};