class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<pair<int, int>> DIR = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<int>> dist(mat.size(), vector<int>(mat[0].size(), 100001));
        queue<pair<int, int>> q;

        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for (int d = 0; d < DIR.size(); d++) {
                int ni = i + DIR[d].first;
                int nj = j + DIR[d].second;
                if (ni >= 0 && nj >= 0 && ni < mat.size() && nj < mat[0].size() && dist[ni][nj] > dist[i][j] + 1) {
                    dist[ni][nj] = dist[i][j] + 1;
                    q.push({ni, nj});
                }
            }
        }

        return dist;
    }


};