class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        dist[0][0] = 0;
        pq.push({dist[0][0], 0, 0});
        while (!pq.empty()) {
            auto [time, x, y] = pq.top(); 
            pq.pop();

            if (time > dist[x][y]) continue;
            if (x == n - 1 && y == m - 1) continue;

            vector<vector<int>> DIR = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (auto d : DIR) {
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                int nTime = max(time, moveTime[nx][ny]) + 1;
                if (nTime < dist[nx][ny]) {
                    dist[nx][ny] = nTime;
                    pq.push({nTime, nx, ny});
                }
            }
        }

        return dist[n - 1][m - 1];
    }
};