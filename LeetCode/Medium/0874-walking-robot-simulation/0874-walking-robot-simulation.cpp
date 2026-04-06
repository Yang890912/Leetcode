class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        const vector<int> dx = {0, 1, 0, -1};
        const vector<int> dy = {1, 0, -1, 0};
        int dir = 0;
        set<pair<int, int>> us;
        for (auto o : obstacles) {
            us.insert({o[0], o[1]});
        }

        int res = 0;
        int x = 0, y = 0;
        for (int i = 0; i < commands.size(); i++) {
            if (commands[i] == -1) dir = (dir + 1) % 4;
            else if (commands[i] == -2) dir = (dir + 3) % 4;
            else {
                int units = commands[i];
                while (units && !us.count({x + dx[dir], y + dy[dir]})) {
                    x += dx[dir];
                    y += dy[dir];
                    units--;
                    res = max(res, x * x + y * y);
                }
            }
        }

        return res;
    }
};