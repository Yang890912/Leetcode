class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;

        for (int i = 0; i < points.size(); i++) {
            double x = points[i][0], y = points[i][1];
            double dist = sqrt(x * x + y * y);
            pq.push({dist, i});
        }
        
        vector<vector<int>> res;
        while (k--) {
            int idx = pq.top().second;
            pq.pop();
            res.push_back({points[idx]});
        }

        return res;
    }
};