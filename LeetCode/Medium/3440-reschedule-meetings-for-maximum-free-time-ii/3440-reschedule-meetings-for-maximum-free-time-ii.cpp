class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gaps;
        vector<pair<int, int>> sortedGaps;
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0) gaps.push_back(startTime[i]);
            else gaps.push_back(startTime[i] - endTime[i - 1]);
            
            sortedGaps.push_back({gaps.back(), j++});
                 
            if (i == n - 1) {
                gaps.push_back(eventTime - endTime[i]);
                sortedGaps.push_back({eventTime - endTime[i], j++});
            }
        }
        sort(sortedGaps.rbegin(), sortedGaps.rend());

        int maxFree = 0;
        for (int i = 0; i < n; i++) {
            int free = 0;
            for (int k = 0; k < 3; k++) {
                if (sortedGaps[k].second != i && 
                    sortedGaps[k].second != i + 1 && 
                    endTime[i] - startTime[i] <= sortedGaps[k].first) {
                    free = endTime[i] - startTime[i];
                    break;
                }
            }
            maxFree = max(maxFree, free + gaps[i] + gaps[i + 1]);
        }

        return maxFree;
    }
};