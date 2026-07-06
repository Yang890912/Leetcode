class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        int n = intervals.size();
        int res = intervals.size();
        int i = 0, j = 1;
        while (i < n && j < n) {
            if (intervals[i][0] <= intervals[j][0] && intervals[j][1] <= intervals[i][1]) res--;
            else i = j;
            j++;
        }

        return res;
    }


};