class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> myEdges(n);

        for(auto& e : edges) {
            myEdges[e[0]].push_back(e[1]);
            myEdges[e[1]].push_back(e[0]);
        }

        int res = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            
            int numNodes = 0;
            int numEdges = 0;

            queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int p = q.front();
                q.pop();
                numNodes++;
                numEdges += myEdges[p].size();
                for (int np : myEdges[p]) {
                    if (visited[np]) continue;
                    q.push(np);
                    visited[np] = true;
                }
            }

            if ((numEdges / 2) == (numNodes * (numNodes - 1) / 2)) res++;
        }

        return res;
    }

};