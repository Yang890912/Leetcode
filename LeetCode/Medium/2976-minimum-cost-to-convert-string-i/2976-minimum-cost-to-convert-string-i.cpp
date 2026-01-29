class Solution {
public:
    const long long INF = 1e12;

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = original.size();
        vector<vector<long long>> dist(26, vector<long long>(26, INF));

        for (int i = 0; i < n; i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min((long long)cost[i], dist[u][v]);
        }

        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (dist[i][j] > dist[i][k] + dist[k][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }

        long long res = 0;
        for (int i = 0; i < source.size(); i++) {
            int s = source[i] - 'a';
            int t = target[i] - 'a';

            if (s == t) continue;
            else if (dist[s][t] == INF) return -1;
            else res += dist[s][t];
        }

        return res;
    }
};