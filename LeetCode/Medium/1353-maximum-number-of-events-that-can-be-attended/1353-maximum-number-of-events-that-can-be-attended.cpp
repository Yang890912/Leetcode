class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());

        int start = events[0][0];
        int end = 0;
        for (const vector<int>& e : events) end = max(end, e[1]);

        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0, res = 0;
        for (int d = start; d <= end; d++) {
            while (i < n && events[i][0] <= d) {
                pq.push(events[i][1]);
                i++;
            }

            while (!pq.empty() && pq.top() < d) pq.pop();   // 超過結束時間

            if (!pq.empty()) {
                pq.pop();
                res++;
            }
        }

        return res;
    }
};