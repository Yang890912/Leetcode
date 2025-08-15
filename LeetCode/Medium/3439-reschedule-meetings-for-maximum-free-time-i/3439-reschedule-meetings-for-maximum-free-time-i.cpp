class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();

        vector<int> gaps;
        for (int i = 0; i < n; i++) {
            if (i == 0) gaps.push_back(startTime[i]);
            else gaps.push_back(startTime[i] - endTime[i - 1]);

            if (i == n - 1 && endTime[i] < eventTime)
                gaps.push_back(eventTime - endTime[i]);
        }

        int maxFree = 0;
        int freeTime = 0;
        for (int i = 0; i < gaps.size(); i++) {
            if (i < k + 1) freeTime += gaps[i];
            else freeTime += gaps[i] - gaps[i - k - 1];
            maxFree = max(maxFree, freeTime);
        }

        return maxFree;
    }
};