class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        vector<long long> dis(n, INT_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        
        for (vector<int>& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, 2 * w});
        }

        dis[0] = 0;
        pq.push({0, 0});
        while (!pq.empty()) {
            long long weight = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if (dis[node] < weight) continue;

            for (pair<int, int> edge : adj[node]) {
                int v = edge.first, w = edge.second;
                if (dis[v] > dis[node] + w) {
                    dis[v] = dis[node] + w;
                    pq.push({dis[v], v});
                }
            }
        }

        return (dis[n - 1] == INT_MAX) ? -1 : dis[n - 1];
    }
};