class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int maxFree = 0;
        int n = startTime.size();
        vector<int> gap(1, startTime[0]);

        for (int i = 1; i < n; i++) {
            gap.push_back(startTime[i] - endTime[i - 1]);
        }
        gap.push_back(eventTime - endTime[n - 1]);

        vector<int> maxRightFree(n + 1, 0);
        int currMax = 0;
        for (int i = n - 1; i >= 1; i--) {
            currMax = max(gap[i + 1], currMax);
            maxRightFree[i] = currMax;
        }

        int maxLeftFree = 0;
        for (int i = 0; i < n; i++) {
            if (i >= 1) maxLeftFree = max(maxLeftFree, gap[i - 1]);
            
            int dur = endTime[i] - startTime[i];
            if (dur <= maxLeftFree || dur <= maxRightFree[i + 1]) maxFree = max(maxFree, gap[i] + gap[i + 1] + dur);
            else maxFree = max(maxFree, gap[i] + gap[i + 1]);
        }

        return maxFree;
    }
};