class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> parent(n, 0);
        vector<int> rank(n, 1);
        vector<int> cost(n, INT_MAX);
        vector<int> res;

        for (int i = 0; i < n; i++) parent[i] = i;

        for (int i = 0; i < edges.size(); i++) {
            int root1 = find(edges[i][0], parent);
            int root2 = find(edges[i][1], parent);

            cost[root2] &= edges[i][2];
            cost[root2] &= cost[root1];
            parent[root1] = root2;
        }

        for (int i = 0; i < query.size(); i++) {
            if (query[i][0] == query[i][1]) res.push_back(0);
            else if (find(query[i][0], parent) != find(query[i][1], parent)) res.push_back(-1);
            else res.push_back(cost[find(query[i][0], parent)]);
        }

        return res;
    }

    int find(int x, vector<int>& parent) {
        if (parent[x] != x) {
            parent[x] = find(parent[x], parent);
        }
        return parent[x];
    }
};