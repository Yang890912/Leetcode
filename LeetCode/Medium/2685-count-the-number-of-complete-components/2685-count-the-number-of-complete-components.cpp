class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool> used(n, false);
        vector<vector<int>> adjacent(n, vector<int>());
        int res = 0;

        for (int i = 0; i < edges.size(); i++) {
            adjacent[edges[i][0]].push_back(edges[i][1]);
            adjacent[edges[i][1]].push_back(edges[i][0]);
        }

        for (int i = 0; i < n; i++) {
            if (used[i]) continue;

            int numOfEdges = 0;
            int numOfNodes = 1;
            queue<int> q;

            q.push(i);
            used[i] = true;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int j = 0; j < adjacent[node].size(); j++) {
                    if (!used[adjacent[node][j]]) {
                        numOfNodes++;
                        q.push(adjacent[node][j]);
                        used[adjacent[node][j]] = true;
                    }
                    numOfEdges++;
                }
            }

            if (numOfEdges == numOfNodes * (numOfNodes - 1)) res++;
        }

        return res;
    }
};