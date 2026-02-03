class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;

        int n = intervals.size();
        int i = 0;
        while (i < n) {
            if (intervals[i][1] < newInterval[0]) res.push_back(intervals[i]);
            else break;
            i++;
        }
        
        res.push_back(newInterval);

        while (i < n) {
            if (intervals[i][0] > newInterval[1]) res.push_back(intervals[i]);
            else {
                res.back()[0] = min(res.back()[0], intervals[i][0]);
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
            i++;
        }

        return res;
    }
};