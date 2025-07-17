class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();
        
        unordered_map<int, int> ans;
        vector<int> myQueries = queries;
        
        sort(myQueries.begin(), myQueries.end());

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq; 
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;
        vector<pair<int, int>> DIR = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int point = 0;

        for (int i = 0; i < myQueries.size(); i++) {
            int query = myQueries[i];
            while (!pq.empty() && pq.top().first < query) {
                int x = pq.top().second.first;
                int y = pq.top().second.second;
                pq.pop();
                point++;

                for (int j = 0; j < DIR.size(); j++) {
                    int nx = x + DIR[j].first;
                    int ny = y + DIR[j].second;
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny] == true) continue;
                    visited[nx][ny] = true;
                    pq.push({grid[nx][ny], {nx, ny}});
                }
            }
            ans[query] = point;
        }
        
        vector<int> res;
        for (int i = 0; i < queries.size(); i++) 
            res.push_back(ans[queries[i]]);

        return res;
    }
};