class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> res;
        
        vector<vector<int>> visited(m, vector<int>(n, 0));
        stack<pair<int, int>> st;
        st.push({0, 0});
        visited[0][0] = 1;
        int round = 0;
        while (!st.empty()) {
            stack<pair<int, int>> tmpSt;
            while (!st.empty()) {
                int x, y;
                x = st.top().first;
                y = st.top().second;
                st.pop();

                if (round % 2 == 0) {
                    if (x + 1 < m && visited[x + 1][y] == 0) {
                        tmpSt.push({x + 1, y});
                        visited[x + 1][y] = 1;
                    }
                    if (y + 1 < n && visited[x][y + 1] == 0) {
                        tmpSt.push({x, y + 1});
                        visited[x][y + 1] = 1;
                    }
                }
                else {
                    if (y + 1 < n && visited[x][y + 1] == 0) {
                        tmpSt.push({x, y + 1});
                        visited[x][y + 1] = 1;
                    }
                    if (x + 1 < m && visited[x + 1][y] == 0) {
                        tmpSt.push({x + 1, y});
                        visited[x + 1][y] = 1;
                    }
                }

                res.push_back(mat[x][y]);
            }

            st = tmpSt;
            round++;
        }

        return res;
    }
};