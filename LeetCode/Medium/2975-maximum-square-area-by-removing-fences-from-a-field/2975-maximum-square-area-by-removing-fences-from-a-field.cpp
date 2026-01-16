class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        vector<int> hDiffs, vDiffs;

        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                hDiffs.push_back(hFences[j] - hFences[i]);
            }
        }

        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                vDiffs.push_back(vFences[j] - vFences[i]);
            }
        }

        sort(hDiffs.begin(), hDiffs.end());
        sort(vDiffs.begin(), vDiffs.end());

        long long res = -1;
        int i = 0;
        int j = 0;

        while (i < hDiffs.size() && j < vDiffs.size()) {
            if (hDiffs[i] == vDiffs[j]) {
                res = max((long long)hDiffs[i] * hDiffs[i], res);
                i++;
                j++;
            }
            else if (hDiffs[i] < vDiffs[j]) i++;
            else if (hDiffs[i] > vDiffs[j]) j++;
        }

        return res % ((int)1e9 + 7);
    }
};