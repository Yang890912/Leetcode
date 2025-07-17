class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<double, int>> dist;
        vector<vector<int>> res;

        for (int i = 0; i < points.size(); i++) {
            dist.push_back({sqrt(points[i][0] * points[i][0] + points[i][1] * points[i][1]), i});
        }
        
        sort(dist.begin(), dist.end());

        for (int i = 0; i < points.size(); i++) {
            if (k == 0) break;
            res.push_back(points[dist[i].second]);
            k--;
        }

        return res;
    }
};