class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> pq;
        int n = classes.size();
        
        for (int i = 0; i < n; i++) {
            double p = classes[i][0];
            double t = classes[i][1];
            double gain = (p + 1) / (t + 1) - p / t;
            pq.push({gain, i});
        }

        while (extraStudents--) {
            int j = pq.top().second;
            pq.pop();
            classes[j][0]++;
            classes[j][1]++;

            double p = classes[j][0];
            double t = classes[j][1];
            double gain = (p + 1) / (t + 1) - p / t;
            pq.push({gain, j});
        }

        double res = 0.0;
        for (int i = 0; i < n; i++) {
            double ratio = (double)classes[i][0] / classes[i][1];
            res += ratio;
        }
        res /= n;

        return res;
    }
};