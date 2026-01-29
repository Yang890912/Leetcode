class Solution {
public:
    const int m = 'a' + 26;

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = original.size();
        vector<vector<long long>> adj(m, vector<long long>(m, 1e12));
        vector<vector<long long>> dis(m, vector<long long>(m, 1e12));
        vector<vector<bool>> found(m, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            adj[original[i]][changed[i]] = min(cost[i], (long long)adj[original[i]][changed[i]]);
        }

        long long res = 0;
        for (int i = 0; i < source.size(); i++) {
            int src = source[i];
            int dst = target[i];
            if (src == dst) continue;
            else if (found[src][dst]) {
                if (dis[src][dst] == (long long)1e12) return -1;
                res += dis[src][dst];
            }
            else {
                findShortestPath(src, dst, adj, dis, found);
                if (dis[src][dst] == (long long)1e12) return -1;
                res += dis[src][dst];
            }
        }

        return res;
    }

    void findShortestPath(  int src, int dst, 
                            vector<vector<long long>>& adj, 
                            vector<vector<long long>>& dis,
                            vector<vector<bool>>& found) {

        vector<bool> used(m, false);

        dis[src][src] = 0;
        for (int i = 'a'; i <= 'z'; i++) {
            long long currMin = 1e12;
            int picked = -1;
            for (int j = 'a'; j <= 'z'; j++) {
                if (used[j]) continue;

                if (dis[src][j] < currMin) {
                    picked = j;
                    currMin = dis[src][j];
                }
            }

            if (picked == -1) break;
            used[picked] = true;

            for (int v = 'a'; v <= 'z'; v++) {
                if (dis[src][v] > dis[src][picked] + adj[picked][v])
                    dis[src][v] = dis[src][picked] + adj[picked][v];
            }
        }

        for (int v = 'a'; v <= 'z'; v++) found[src][v] = true;  
    }
};