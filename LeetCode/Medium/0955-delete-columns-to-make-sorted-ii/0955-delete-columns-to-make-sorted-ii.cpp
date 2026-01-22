class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size();
        int n = strs[0].size();
        int res = 0;

        while (!isSorted(strs)) {
            int pos = -1;
            for (int i = 0; i < m - 1; i++) {
                if (strs[i] <= strs[i + 1]) continue;
                
                for (int j = 0; j < n; j++) {
                    if (strs[i][j] > strs[i + 1][j]) {
                        pos = j;
                        break;
                    }
                }

                if (pos != -1) break;
            }

            res++;

            for (int i = 0; i < m; i++) strs[i][pos] = ' ';
        }

        return res;
    }

    bool isSorted(vector<string>& strs) {
        for (int i = 0; i < strs.size() - 1; i++) {
            if (strs[i + 1] < strs[i]) return false;
        }
        return true;
    }
};