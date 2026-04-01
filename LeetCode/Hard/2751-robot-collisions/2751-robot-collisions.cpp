class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        struct Robot {
            int idx;
            int pos;
            int health;
            char dir;
        };
        int n = positions.size();
        vector<Robot> robot;

        for (int i = 0; i < n; i++) {
            Robot r = {i, positions[i], healths[i], directions[i]};
            robot.push_back(r);
        }

        sort(robot.begin(), robot.end(), [](Robot a, Robot b) {
            return a.pos < b.pos;
        });

        stack<pair<int, int>> st;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++) {
            if (robot[i].dir == 'R') st.push({robot[i].idx, robot[i].health});
            else {
                while (!st.empty() && robot[i].health > st.top().second) {
                    robot[i].health--;
                    st.pop();
                }

                if (st.empty()) pq.push({robot[i].idx, robot[i].health});
                else {
                    int _idx = st.top().first;
                    int _top = st.top().second;
                    st.pop();
                    if (robot[i].health < _top) st.push({_idx, _top - 1});
                }
            }
        }

        while (!st.empty()) {
            pq.push(st.top());
            st.pop();
        }

        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
};