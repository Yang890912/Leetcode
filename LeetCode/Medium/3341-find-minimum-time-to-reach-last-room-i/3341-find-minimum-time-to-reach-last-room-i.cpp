class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<vector<int>> DIR = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        dist[0][0] = 0;
        pq.push({dist[0][0], {0, 0}});
        while (!pq.empty()) {
            int time = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if (time > dist[x][y]) continue;
            if (x == n - 1 && y == m - 1) return dist[n - 1][m - 1];

            for (vector<int> d : DIR) {
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                int nTime = max(time, moveTime[nx][ny]) + 1;
                if (nTime < dist[nx][ny]) {
                    dist[nx][ny] = nTime;
                    pq.push({nTime, {nx, ny}});
                }
            }
        }
        return -1;
    }
};