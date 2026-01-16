class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int hMax = 1, vMax = 1;
        int i = 1, j = 1;
        while (i < hBars.size()) {
            int hTmp = 1;  
            while (i < hBars.size() && hBars[i] == hBars[i - 1] + 1) {
                hTmp++;
                i++;
            }
            hMax = max(hMax, hTmp);
            i++;
        }

        while (j < vBars.size()) {
            int vTmp = 1;
            while (j < vBars.size() && vBars[j] == vBars[j - 1] + 1) {
                vTmp++;
                j++;
            }
            vMax = max(vMax, vTmp);
            j++;
        }

        int sideLen = min(hMax + 1, vMax + 1);

        return sideLen * sideLen;
    }
};