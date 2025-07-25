class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int> dis1(edges.size(), -1);
        vector<int> dis2(edges.size(), -1);
        
        bfs(node1, dis1, edges);
        bfs(node2, dis2, edges);

        int res = -1;
        int currMin = INT_MAX;
        for (int i = 0; i < dis1.size(); i++) {
            if (dis1[i] == -1 || dis2[i] == -1) continue;
            if (max(dis1[i], dis2[i]) < currMin) {
                currMin = max(dis1[i], dis2[i]);
                res = i;
            }
        }

        return res;
    }

    void bfs(int start, vector<int>& dis, vector<int>& edges) {
        queue<pair<int, int>> q;
        q.push({start, 0});
        dis[start] = 0;
        while (!q.empty()) {
            int node = q.front().first;
            int d = q.front().second;
            q.pop();

            if (edges[node] != -1 && dis[edges[node]] == -1) {
                q.push({edges[node], d + 1});
                dis[edges[node]] = d + 1;
            }
        }
    }
};