class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int res = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int land = landStartTime[i] + landDuration[i];
                int water = waterStartTime[j] + waterDuration[j];

                if (land < waterStartTime[j]) res = min(res, water);
                else res = min(res, land + waterDuration[j]);

                if (water < landStartTime[i]) res = min(res, land);
                else res = min(res, water + landDuration[i]);
            }
        }

        return res;
    }
};