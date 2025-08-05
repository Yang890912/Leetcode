class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        vector<int> candiates(2, -1);
        candiates[0] = tops[0];
        candiates[1] = bottoms[0];
        for (int i = 1; i < n; i++) {
            if (candiates[0] != tops[i] && candiates[0] != bottoms[i]) {
                candiates[0] = -1;
            }
            if (candiates[1] != tops[i] && candiates[1] != bottoms[i]) {
                candiates[1] = -1;
            }
        }

        if (candiates[0] == -1 && candiates[1] == -1) return -1;

        int res = INT_MAX;
        for (int i = 0; i < 2; i++) {
            if (candiates[i] == -1) continue;

            int currRes = 0;
            for (int j = 0; j < n; j++) {
                if (tops[j] == candiates[i]) currRes++;
            }
            currRes = min(currRes, n - currRes);
            res = min(res, currRes);

            currRes = 0;
            for (int j = 0; j < n; j++) {
                if (bottoms[j] == candiates[i]) currRes++;
            }
            currRes = min(currRes, n - currRes);
            res = min(res, currRes);
        }

        return res;
    }
};