class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> graph;

        for (int i = 0; i < roads.size(); i++) {
            graph[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            graph[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        const int MOD = 1e9 + 7;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        while (!pq.empty()) {
            int node = pq.top().second;
            long long time = pq.top().first;
            vector<pair<int, int>> neighbors = graph[node];
            pq.pop();

            for (int i = 0; i < neighbors.size(); i++) {
                if (time + neighbors[i].second < dist[neighbors[i].first]) {
                    dist[neighbors[i].first] = time + neighbors[i].second;
                    ways[neighbors[i].first] = ways[node];
                    pq.push({dist[neighbors[i].first], neighbors[i].first});
                }
                else if (time + neighbors[i].second == dist[neighbors[i].first]) {
                    ways[neighbors[i].first] = (ways[neighbors[i].first] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};