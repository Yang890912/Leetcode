class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int res = INT_MAX;

        for (int i = 0; i < n; i++) {
            int tmp = landStartTime[i] + landDuration[i];
            for (int j = 0; j < m; j++) {
                if (tmp < waterStartTime[j]) res = min(res, waterStartTime[j] + waterDuration[j]);
                else res = min(res, tmp + waterDuration[j]);
            }
        }

        for (int j = 0; j < m; j++) {
            int tmp = waterStartTime[j] + waterDuration[j];
            for (int i = 0; i < n; i++) {
                if (tmp < landStartTime[i]) res = min(res, landStartTime[i] + landDuration[i]);
                else res = min(res, tmp + landDuration[i]);
            }
        }

        return res;
    }
};