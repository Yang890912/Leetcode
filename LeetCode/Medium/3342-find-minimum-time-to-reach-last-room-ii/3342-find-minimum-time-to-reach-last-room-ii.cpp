class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<>> pq;
        vector<vector<int>> DIR = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        dist[0][0] = 0;
        pq.push({dist[0][0], {0, 0, 2}});
        while (!pq.empty()) {
            int time = pq.top().first;
            int x = pq.top().second[0];
            int y = pq.top().second[1];
            int cost = (pq.top().second[2] == 2) ? 1 : 2;
            pq.pop();

            if (time > dist[x][y]) continue;
            if (x == n - 1 && y == m - 1) return dist[n - 1][m - 1];

            for (int i = 0; i < 4; i++) {
                int nx = x + DIR[i][0];
                int ny = y + DIR[i][1];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                int nTime = max(time, moveTime[nx][ny]) + cost;
                if (nTime < dist[nx][ny]) {
                    dist[nx][ny] = nTime;
                    pq.push({nTime, {nx, ny, cost}});
                }
            }
        }

        return -1;
    }
};