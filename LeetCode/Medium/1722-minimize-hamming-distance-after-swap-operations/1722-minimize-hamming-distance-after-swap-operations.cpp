class DSU {
public:
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    void unite(int a, int b) {
        parent[find(a)] = find(b);
    }

private:
    vector<int> parent;
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        DSU dsu = DSU(n);

        for (auto& pair : allowedSwaps) {
            dsu.unite(pair[0], pair[1]);
        }

        int res = 0;
        unordered_map<int, multiset<int>> group;
        for (int i = 0; i < n; i++) {
            group[dsu.find(i)].insert(source[i]);
        }
        for (int i = 0; i < n; i++) {
            if (group[dsu.find(i)].count(target[i]) == 0) res++;
            else {
                auto it = group[dsu.find(i)].find(target[i]);
                if (it != group[dsu.find(i)].end()) {
                    group[dsu.find(i)].erase(it);
                }
            }
        }

        return res;
    }
};