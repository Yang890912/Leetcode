class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int, int>> xs, ys;

        for (int i = 0 ; i < rectangles.size(); i++) {
            xs.push_back({rectangles[i][0], rectangles[i][2]});
            ys.push_back({rectangles[i][1], rectangles[i][3]});
        }

        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());
        int lines = 0;
        int curr = xs[0].second;

        for (int i = 1 ; i < xs.size(); i++) {
            if (xs[i].first < curr) curr = max(curr, xs[i].second);
            else {
                curr = max(curr, xs[i].second);
                lines++;
            }
            if (lines >= 2) return true;
        }

        lines = 0;
        curr = ys[0].second;

        for (int i = 1 ; i < ys.size(); i++) {
            if (ys[i].first < curr) curr = max(curr, ys[i].second);
            else {
                curr = max(curr, ys[i].second);
                lines++;
            }
            if (lines >= 2) return true;
        }

        return false;
    }
};